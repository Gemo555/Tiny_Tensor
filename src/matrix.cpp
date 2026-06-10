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
    //   Implement this yourself.
    //   Think about:
    //   1. What invariants should Matrix maintain?
    //   2. How should row and column counts relate to storage size?
    //   3. Should zero-sized matrices be allowed?
    //   4. What initial value should each element have?
    //   Do not ask AI to complete this function until you can explain the design.
    throw_handwrite_todo("Matrix::Matrix(rows, cols)");
}

Matrix::Matrix(std::size_t rows, std::size_t cols, double value) {
    (void)rows;
    (void)cols;
    (void)value;
    // TODO(handwrite):
    //   Implement this yourself after the basic constructor is clear.
    //   Think about whether this constructor should reuse fill().
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
    //   Implement this yourself.
    //   Think about:
    //   1. How should row and column indices map to contiguous storage?
    //   2. What should happen on out-of-range access?
    //   3. Should const and non-const access share the same index calculation?
    //   Do not ask AI to complete this function until you can explain the design.
    throw_handwrite_todo("Matrix::operator()(row, col)");
}

const double& Matrix::operator()(std::size_t row, std::size_t col) const {
    (void)row;
    (void)col;
    // TODO(handwrite):
    //   Implement this yourself.
    //   Keep behavior consistent with the non-const overload.
    throw_handwrite_todo("Matrix::operator()(row, col) const");
}

void Matrix::fill(double value) {
    (void)value;
    // TODO(handwrite):
    //   Implement this yourself.
    //   Think about whether fill should change shape or only existing elements.
    throw_handwrite_todo("Matrix::fill(value)");
}

Matrix Matrix::zeros(std::size_t rows, std::size_t cols) {
    (void)rows;
    (void)cols;
    // TODO(handwrite):
    //   Implement this yourself after the constructor and fill are clear.
    throw_handwrite_todo("Matrix::zeros(rows, cols)");
}

Matrix Matrix::ones(std::size_t rows, std::size_t cols) {
    (void)rows;
    (void)cols;
    // TODO(handwrite):
    //   Implement this yourself after zeros is clear.
    throw_handwrite_todo("Matrix::ones(rows, cols)");
}

Matrix Matrix::transpose() const {
    // TODO(handwrite):
    //   Implement this yourself.
    //   Think about:
    //   1. What should the output shape be?
    //   2. Which input element maps to each output element?
    //   3. Does this version copy data or create a view?
    //   Do not ask AI to complete this function until you can explain the design.
    throw_handwrite_todo("Matrix::transpose()");
}

Matrix Matrix::matmul(const Matrix& other) const {
    (void)other;
    // TODO(handwrite):
    //   Implement this yourself.
    //   Think about:
    //   1. What dimensions are valid for A.matmul(B)?
    //   2. What should happen when dimensions do not match?
    //   3. What are the three loops in naive matrix multiplication?
    //   4. Which memory access pattern is cache-friendly?
    //   Do not ask AI to complete this function until you can explain the design.
    throw_handwrite_todo("Matrix::matmul(other)");
}

}  // namespace tinytensor
