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
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_ * cols_);
}

Matrix::Matrix(std::size_t rows, std::size_t cols, double value) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_ * cols_, value);
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
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Matrix index out of range");
    }

    return data_[row * cols_ + col];
}

const double& Matrix::operator()(std::size_t row, std::size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Matrix index out of range");
    }

    return data_[row * cols_ + col];
}

void Matrix::fill(double value) {
    for (std::size_t i = 0; i < data_.size(); ++i) {
        data_[i] = value;
    }
}

Matrix Matrix::zeros(std::size_t rows, std::size_t cols) {
    Matrix m(rows, cols);
    m.fill(0.0);
    return m;
}

Matrix Matrix::ones(std::size_t rows, std::size_t cols) {
    Matrix m(rows, cols);
    m.fill(1.0);
    return m;
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
