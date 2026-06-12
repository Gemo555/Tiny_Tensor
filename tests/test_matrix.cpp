#include "tinytensor/matrix.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

int failures = 0;

void require(bool condition, const std::string& message) {
    if (!condition) {
        ++failures;
        std::cerr << "失败: " << message << '\n';
    }
}

void require_equal(double actual, double expected, const std::string& message) {
    if (actual != expected) {
        ++failures;
        std::cerr << "失败: " << message << "，期望 " << expected << "，实际 " << actual << '\n';
    }
}

void section(const std::string& name) {
    std::cout << "\n[ " << name << " ]\n";
}

bool learning_tests_enabled() {
    return std::getenv("RUN_LEARNING_TESTS") != nullptr;
}

}  // namespace

int main() {
    using tinytensor::Matrix;

    section("Smoke tests: 现在应该通过");
    Matrix empty;
    require(empty.rows() == 0, "默认 Matrix 的行数是 0");
    require(empty.cols() == 0, "默认 Matrix 的列数是 0");
    require(empty.size() == 0, "默认 Matrix 的元素数量是 0");
    require(empty.empty(), "默认 Matrix 是空的");

    if (!learning_tests_enabled()) {
        std::cout << "\n已跳过 learning tests。设置 RUN_LEARNING_TESTS=1 可以运行完整 Matrix 行为测试。\n";
        return failures == 0 ? 0 : 1;
    }

    section("Learning tests: Matrix 基础行为");

    try {
        Matrix matrix(2, 3);
        require(matrix.rows() == 2, "Matrix(2, 3) 的行数是 2");
        require(matrix.cols() == 3, "Matrix(2, 3) 的列数是 3");
        require(matrix.size() == 6, "Matrix(2, 3) 存储 6 个元素");
        require(!matrix.empty(), "Matrix(2, 3) 不是空矩阵");
    } catch (const std::exception& e) {
        require(false, std::string("构造函数不应该抛异常: ") + e.what());
    }

    try {
        Matrix matrix(2, 2, 3.5);
        require_equal(matrix(0, 0), 3.5, "带初值构造函数初始化元素 (0, 0)");
        require_equal(matrix(1, 1), 3.5, "带初值构造函数初始化元素 (1, 1)");
    } catch (const std::exception& e) {
        require(false, std::string("带初值构造函数不应该抛异常: ") + e.what());
    }

    try {
        Matrix matrix = Matrix::zeros(2, 2);
        require_equal(matrix(0, 0), 0.0, "zeros 初始化元素 (0, 0)");
        require_equal(matrix(1, 1), 0.0, "zeros 初始化元素 (1, 1)");
    } catch (const std::exception& e) {
        require(false, std::string("zeros/operator() 不应该抛异常: ") + e.what());
    }

    try {
        Matrix matrix = Matrix::ones(2, 2);
        matrix.fill(4.0);
        require_equal(matrix(0, 0), 4.0, "fill 写入元素 (0, 0)");
        require_equal(matrix(1, 1), 4.0, "fill 写入元素 (1, 1)");
    } catch (const std::exception& e) {
        require(false, std::string("ones/fill/operator() 不应该抛异常: ") + e.what());
    }

    try {
        Matrix matrix(2, 3);
        matrix(0, 1) = 7.0;
        require_equal(matrix(0, 1), 7.0, "operator() 可以写入并读回一个元素");
    } catch (const std::exception& e) {
        require(false, std::string("operator() 不应该抛异常: ") + e.what());
    }

    section("Learning tests: 越界和错误参数");

    try {
        Matrix matrix(2, 3);
        (void)matrix(2, 0);
        require(false, "row 越界时应该抛出 std::out_of_range");
    } catch (const std::out_of_range&) {
        require(true, "row 越界抛出 std::out_of_range");
    } catch (const std::exception& e) {
        require(false, std::string("row 越界抛出了错误的异常类型: ") + e.what());
    }

    try {
        Matrix matrix(2, 3);
        (void)matrix(0, 3);
        require(false, "col 越界时应该抛出 std::out_of_range");
    } catch (const std::out_of_range&) {
        require(true, "col 越界抛出 std::out_of_range");
    } catch (const std::exception& e) {
        require(false, std::string("col 越界抛出了错误的异常类型: ") + e.what());
    }

    try {
        Matrix left(2, 3);
        Matrix right(2, 2);
        (void)left.matmul(right);
        require(false, "matmul 维度不匹配时应该抛出 std::invalid_argument");
    } catch (const std::invalid_argument&) {
        require(true, "matmul 维度不匹配抛出 std::invalid_argument");
    } catch (const std::exception& e) {
        require(false, std::string("matmul 维度错误抛出了错误的异常类型: ") + e.what());
    }

    section("Learning tests: transpose 具体数值");

    try {
        Matrix matrix(2, 3);
        matrix(0, 0) = 1.0;
        matrix(0, 1) = 2.0;
        matrix(0, 2) = 3.0;
        matrix(1, 0) = 4.0;
        matrix(1, 1) = 5.0;
        matrix(1, 2) = 6.0;

        Matrix transposed = matrix.transpose();
        require(transposed.rows() == 3, "transpose 交换行数");
        require(transposed.cols() == 2, "transpose 交换列数");
        require_equal(transposed(0, 0), 1.0, "transpose 元素 (0, 0)");
        require_equal(transposed(1, 0), 2.0, "transpose 元素 (1, 0)");
        require_equal(transposed(2, 0), 3.0, "transpose 元素 (2, 0)");
        require_equal(transposed(0, 1), 4.0, "transpose 元素 (0, 1)");
        require_equal(transposed(1, 1), 5.0, "transpose 元素 (1, 1)");
        require_equal(transposed(2, 1), 6.0, "transpose 元素 (2, 1)");
    } catch (const std::exception& e) {
        require(false, std::string("transpose 不应该抛异常: ") + e.what());
    }

    section("Learning tests: matmul 具体数值");

    try {
        Matrix left(2, 3);
        left(0, 0) = 1.0;
        left(0, 1) = 2.0;
        left(0, 2) = 3.0;
        left(1, 0) = 4.0;
        left(1, 1) = 5.0;
        left(1, 2) = 6.0;

        Matrix right(3, 2);
        right(0, 0) = 7.0;
        right(0, 1) = 8.0;
        right(1, 0) = 9.0;
        right(1, 1) = 10.0;
        right(2, 0) = 11.0;
        right(2, 1) = 12.0;

        Matrix result = left.matmul(right);
        require(result.rows() == 2, "matmul 结果行数等于左矩阵行数");
        require(result.cols() == 2, "matmul 结果列数等于右矩阵列数");
        require_equal(result(0, 0), 58.0, "matmul 元素 (0, 0)");
        require_equal(result(0, 1), 64.0, "matmul 元素 (0, 1)");
        require_equal(result(1, 0), 139.0, "matmul 元素 (1, 0)");
        require_equal(result(1, 1), 154.0, "matmul 元素 (1, 1)");
    } catch (const std::exception& e) {
        require(false, std::string("matmul 不应该抛异常: ") + e.what());
    }

    return failures == 0 ? 0 : 1;
}
