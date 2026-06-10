#include "tinytensor/matrix.hpp"

#include <iostream>

int main() {
    tinytensor::Matrix matrix;

    std::cout << "Tiny Tensor Matrix example\n";
    std::cout << "rows: " << matrix.rows() << '\n';
    std::cout << "cols: " << matrix.cols() << '\n';
    std::cout << "size: " << matrix.size() << '\n';
    std::cout << "empty: " << (matrix.empty() ? "true" : "false") << '\n';
    std::cout << "Next step: handwrite Matrix(rows, cols) in src/matrix.cpp\n";

    return 0;
}
