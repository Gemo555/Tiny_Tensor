#include "tinytensor/matrix.hpp"

#include <iostream>

int main() {
    tinytensor::Matrix matrix(2, 3);

    matrix(0, 0) = 1.0;
    matrix(0, 1) = 2.0;
    matrix(0, 2) = 3.0;
    matrix(1, 0) = 4.0;
    matrix(1, 1) = 5.0;
    matrix(1, 2) = 6.0;

    tinytensor::Matrix transposed = matrix.transpose();

    std::cout << "Tiny Tensor Matrix 示例\n";
    std::cout << "原矩阵 shape: " << matrix.rows() << " x " << matrix.cols() << '\n';
    std::cout << "转置后 shape: " << transposed.rows() << " x " << transposed.cols() << '\n';
    std::cout << "matrix(1, 2): " << matrix(1, 2) << '\n';
    std::cout << "transposed(2, 1): " << transposed(2, 1) << '\n';
    std::cout << "下一步: 补充更多 Matrix 测试，并整理 row-major / matmul 学习说明\n";

    return 0;
}
