#include "tinytensor/matrix.hpp"

#include <stdexcept>

namespace tinytensor {

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
    Matrix m(cols_, rows_);

    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            m(j, i) = (*this)(i, j);
        }
    }

    return m;
}

Matrix Matrix::matmul(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Matrix dimensions do not match for matmul");
    }

    Matrix m = zeros(rows_, other.cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t k = 0; k < cols_; ++k) {
            for (std::size_t j = 0; j < other.cols_; ++j) {
                m(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }

    return m;
}

}  // namespace tinytensor
