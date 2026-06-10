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
        std::cerr << "FAILED: " << message << '\n';
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

    section("Smoke tests: should pass now");
    Matrix empty;
    require(empty.rows() == 0, "default Matrix has 0 rows");
    require(empty.cols() == 0, "default Matrix has 0 cols");
    require(empty.size() == 0, "default Matrix has 0 elements");
    require(empty.empty(), "default Matrix is empty");

    if (!learning_tests_enabled()) {
        std::cout << "\nLearning tests skipped. Set RUN_LEARNING_TESTS=1 after handwriting Matrix.\n";
        return failures == 0 ? 0 : 1;
    }

    section("Learning tests: expected to fail until TODO(handwrite) is implemented");

    try {
        Matrix matrix(2, 3);
        require(matrix.rows() == 2, "Matrix(2, 3) reports 2 rows");
        require(matrix.cols() == 3, "Matrix(2, 3) reports 3 cols");
        require(matrix.size() == 6, "Matrix(2, 3) stores 6 elements");
        require(!matrix.empty(), "Matrix(2, 3) is not empty");
    } catch (const std::logic_error&) {
        require(false, "constructor still throws TODO(handwrite)");
    }

    try {
        Matrix matrix = Matrix::zeros(2, 2);
        require(matrix(0, 0) == 0.0, "zeros initializes element (0, 0)");
        require(matrix(1, 1) == 0.0, "zeros initializes element (1, 1)");
    } catch (const std::logic_error&) {
        require(false, "zeros/operator() still throws TODO(handwrite)");
    }

    try {
        Matrix matrix = Matrix::ones(2, 2);
        matrix.fill(4.0);
        require(matrix(0, 0) == 4.0, "fill writes element (0, 0)");
        require(matrix(1, 1) == 4.0, "fill writes element (1, 1)");
    } catch (const std::logic_error&) {
        require(false, "ones/fill/operator() still throws TODO(handwrite)");
    }

    try {
        Matrix matrix(2, 3);
        matrix(0, 1) = 7.0;
        require(matrix(0, 1) == 7.0, "operator() can write and read one element");
    } catch (const std::logic_error&) {
        require(false, "operator() still throws TODO(handwrite)");
    }

    try {
        Matrix matrix(2, 3, 1.0);
        Matrix transposed = matrix.transpose();
        require(transposed.rows() == 3, "transpose swaps rows");
        require(transposed.cols() == 2, "transpose swaps cols");
    } catch (const std::logic_error&) {
        require(false, "transpose still throws TODO(handwrite)");
    }

    try {
        Matrix left(2, 3, 1.0);
        Matrix right(3, 2, 1.0);
        Matrix result = left.matmul(right);
        require(result.rows() == 2, "matmul result rows match left rows");
        require(result.cols() == 2, "matmul result cols match right cols");
        require(result(0, 0) == 3.0, "matmul computes a simple dot product");
    } catch (const std::logic_error&) {
        require(false, "matmul still throws TODO(handwrite)");
    }

    return failures == 0 ? 0 : 1;
}
