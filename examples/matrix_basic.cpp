#include "tinytensor/matrix.hpp"

#include <iostream>

int main() {
    tinytensor::Matrix matrix;

    std::cout << "Tiny Tensor Matrix 示例\n";
    std::cout << "行数: " << matrix.rows() << '\n';
    std::cout << "列数: " << matrix.cols() << '\n';
    std::cout << "元素数量: " << matrix.size() << '\n';
    std::cout << "是否为空: " << (matrix.empty() ? "是" : "否") << '\n';
    std::cout << "下一步: 在 src/matrix.cpp 里手写 Matrix(rows, cols)\n";

    return 0;
}
