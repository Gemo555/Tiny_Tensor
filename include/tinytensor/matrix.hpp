#pragma once

#include <cstddef>
#include <vector>

namespace tinytensor {

class Matrix {
public:
    Matrix() = default;
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, double value);

    std::size_t rows() const noexcept;
    std::size_t cols() const noexcept;
    std::size_t size() const noexcept;
    bool empty() const noexcept;

    double& operator()(std::size_t row, std::size_t col);
    const double& operator()(std::size_t row, std::size_t col) const;

    void fill(double value);

    static Matrix zeros(std::size_t rows, std::size_t cols);
    static Matrix ones(std::size_t rows, std::size_t cols);

    Matrix transpose() const;
    Matrix matmul(const Matrix& other) const;

private:
    std::size_t rows_{0};
    std::size_t cols_{0};
    std::vector<double> data_{};
};

}  // namespace tinytensor
