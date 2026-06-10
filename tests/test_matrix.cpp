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

void section(const std::string& name) {
    std::cout << "\n[ " << name << " ]\n";
}

bool learning_tests_enabled() {
    return std::getenv("RUN_LEARNING_TESTS") != nullptr;
}

}  // namespace

int main() {
    using tinytensor::Matrix;

    section("Smoke tests：现在应该通过");
    Matrix empty;
    require(empty.rows() == 0, "默认 Matrix 的行数是 0");
    require(empty.cols() == 0, "默认 Matrix 的列数是 0");
    require(empty.size() == 0, "默认 Matrix 的元素数量是 0");
    require(empty.empty(), "默认 Matrix 是空的");

    if (!learning_tests_enabled()) {
        std::cout << "\n已跳过 learning tests。等你手写 Matrix 后，设置 RUN_LEARNING_TESTS=1 再运行。\n";
        return failures == 0 ? 0 : 1;
    }

    section("Learning tests：在 TODO(handwrite) 完成前，预期会失败");

    try {
        Matrix matrix(2, 3);
        require(matrix.rows() == 2, "Matrix(2, 3) 的行数是 2");
        require(matrix.cols() == 3, "Matrix(2, 3) 的列数是 3");
        require(matrix.size() == 6, "Matrix(2, 3) 存储 6 个元素");
        require(!matrix.empty(), "Matrix(2, 3) 不是空矩阵");
    } catch (const std::logic_error&) {
        require(false, "构造函数仍然抛出 TODO(handwrite)");
    }

    try {
        Matrix matrix = Matrix::zeros(2, 2);
        require(matrix(0, 0) == 0.0, "zeros 初始化元素 (0, 0)");
        require(matrix(1, 1) == 0.0, "zeros 初始化元素 (1, 1)");
    } catch (const std::logic_error&) {
        require(false, "zeros/operator() 仍然抛出 TODO(handwrite)");
    }

    try {
        Matrix matrix = Matrix::ones(2, 2);
        matrix.fill(4.0);
        require(matrix(0, 0) == 4.0, "fill 写入元素 (0, 0)");
        require(matrix(1, 1) == 4.0, "fill 写入元素 (1, 1)");
    } catch (const std::logic_error&) {
        require(false, "ones/fill/operator() 仍然抛出 TODO(handwrite)");
    }

    try {
        Matrix matrix(2, 3);
        matrix(0, 1) = 7.0;
        require(matrix(0, 1) == 7.0, "operator() 可以写入并读回一个元素");
    } catch (const std::logic_error&) {
        require(false, "operator() 仍然抛出 TODO(handwrite)");
    }

    try {
        Matrix matrix(2, 3, 1.0);
        Matrix transposed = matrix.transpose();
        require(transposed.rows() == 3, "transpose 交换行数");
        require(transposed.cols() == 2, "transpose 交换列数");
    } catch (const std::logic_error&) {
        require(false, "transpose 仍然抛出 TODO(handwrite)");
    }

    try {
        Matrix left(2, 3, 1.0);
        Matrix right(3, 2, 1.0);
        Matrix result = left.matmul(right);
        require(result.rows() == 2, "matmul 结果行数等于左矩阵行数");
        require(result.cols() == 2, "matmul 结果列数等于右矩阵列数");
        require(result(0, 0) == 3.0, "matmul 能算出一个简单点积");
    } catch (const std::logic_error&) {
        require(false, "matmul 仍然抛出 TODO(handwrite)");
    }

    return failures == 0 ? 0 : 1;
}
