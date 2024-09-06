#include "matrix.h"
#include <iostream>

int main() {
    try {
        // Test matrix creation and element access
        Matrix<int> m1(2, 2);
        m1(0, 0) = 1; m1(0, 1) = 2;
        m1(1, 0) = 3; m1(1, 1) = 4;
        std::cout << "Matrix m1:" << std::endl;
        m1.print();

        Matrix<int> m2(2, 2);
        m2(0, 0) = 5; m2(0, 1) = 6;
        m2(1, 0) = 7; m2(1, 1) = 8;
        std::cout << "Matrix m2:" << std::endl;
        m2.print();

        // Test matrix addition
        Matrix<int> m3 = m1 + m2;
        std::cout << "m1 + m2:" << std::endl;
        m3.print();

        // Test matrix subtraction
        Matrix<int> m4 = m1 - m2;
        std::cout << "m1 - m2:" << std::endl;
        m4.print();

        // Test matrix multiplication
        Matrix<int> m5 = m1 * m2;
        std::cout << "m1 * m2:" << std::endl;
        m5.print();

        // Test copy constructor and assignment operator
        Matrix<int> m6 = m1;
        std::cout << "m6 (copy of m1):" << std::endl;
        m6.print();

        Matrix<int> m7;
        m7 = m2;
        std::cout << "m7 (assigned m2):" << std::endl;
        m7.print();

        // Test error handling
        try {
            Matrix<int> m8(2, 3);
            Matrix<int> m9(2, 2);
            Matrix<int> m10 = m8 + m9;  // This should throw an exception
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        try {
            Matrix<int> m11(2, 2);
            m11(2, 2) = 1;  // This should throw an exception
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}