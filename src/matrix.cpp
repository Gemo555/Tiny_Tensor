#include "tinytensor/matrix.hpp"

#include <stdexcept>
#include <string>

namespace tinytensor {

namespace {

[[noreturn]] void throw_handwrite_todo(const char* function_name) {
    throw std::logic_error(std::string(function_name) + ": TODO(handwrite)");
}

}  // namespace

Matrix::Matrix(std::size_t rows, std::size_t cols) {
    (void)rows;
    (void)cols;
    // TODO(handwrite):
    //   请你自己实现这里。
    //   思考：
    //   1. Matrix 应该维护哪些不变量？
    //   2. rows、cols 和 data_ 的大小应该是什么关系？
    //   3. 是否允许 0 行或 0 列的矩阵？
    //   4. 每个元素的初始值应该是什么？
    //   在你能解释清楚设计之前，不要让 AI 直接补完这个函数。
    throw_handwrite_todo("Matrix::Matrix(rows, cols)");
}

Matrix::Matrix(std::size_t rows, std::size_t cols, double value) {
    (void)rows;
    (void)cols;
    (void)value;
    // TODO(handwrite):
    //   请在理解基础构造函数后自己实现这里。
    //   思考：这个构造函数是否应该复用 fill()？
    throw_handwrite_todo("Matrix::Matrix(rows, cols, value)");
}

std::size_t Matrix::rows() const noexcept {
    return rows_;
}

std::size_t Matrix::cols() const noexcept {
    return cols_;
}

std::size_t Matrix::size() const noexcept {
    return data_.size();
}

bool Matrix::empty() const noexcept {
    return data_.empty();
}

double& Matrix::operator()(std::size_t row, std::size_t col) {
    (void)row;
    (void)col;
    // TODO(handwrite):
    //   请你自己实现这里。
    //   思考：
    //   1. row 和 col 应该如何映射到连续存储 data_ 的下标？
    //   2. 如果访问越界，应该发生什么？
    //   3. const 和非 const 版本是否应该复用同一套下标计算逻辑？
    //   在你能解释清楚设计之前，不要让 AI 直接补完这个函数。
    throw_handwrite_todo("Matrix::operator()(row, col)");
}

const double& Matrix::operator()(std::size_t row, std::size_t col) const {
    (void)row;
    (void)col;
    // TODO(handwrite):
    //   请你自己实现这里。
    //   行为要和非 const 版本保持一致。
    throw_handwrite_todo("Matrix::operator()(row, col) const");
}

void Matrix::fill(double value) {
    (void)value;
    // TODO(handwrite):
    //   请你自己实现这里。
    //   思考：fill 应该改变矩阵形状，还是只修改已有元素？
    throw_handwrite_todo("Matrix::fill(value)");
}

Matrix Matrix::zeros(std::size_t rows, std::size_t cols) {
    (void)rows;
    (void)cols;
    // TODO(handwrite):
    //   请在理解构造函数和 fill 后自己实现这里。
    throw_handwrite_todo("Matrix::zeros(rows, cols)");
}

Matrix Matrix::ones(std::size_t rows, std::size_t cols) {
    (void)rows;
    (void)cols;
    // TODO(handwrite):
    //   请在理解 zeros 后自己实现这里。
    throw_handwrite_todo("Matrix::ones(rows, cols)");
}

Matrix Matrix::transpose() const {
    // TODO(handwrite):
    //   请你自己实现这里。
    //   思考：
    //   1. 输出矩阵的 shape 应该是什么？
    //   2. 输入矩阵的哪个元素会映射到输出矩阵的哪个元素？
    //   3. 当前版本应该复制数据，还是创建 view？
    //   在你能解释清楚设计之前，不要让 AI 直接补完这个函数。
    throw_handwrite_todo("Matrix::transpose()");
}

Matrix Matrix::matmul(const Matrix& other) const {
    (void)other;
    // TODO(handwrite):
    //   请你自己实现这里。
    //   思考：
    //   1. A.matmul(B) 对维度有什么要求？
    //   2. 维度不匹配时应该发生什么？
    //   3. 朴素矩阵乘法的三层循环分别是什么？
    //   4. 哪种内存访问模式更适合缓存？
    //   在你能解释清楚设计之前，不要让 AI 直接补完这个函数。
    throw_handwrite_todo("Matrix::matmul(other)");
}

}  // namespace tinytensor
