#include "polynomial.h"
#include <iostream>

int main() {
    Polynomial p1, p2, result;

    // Test adding terms
    p1.addTerm(3, 2);  // 3x^2
    p1.addTerm(-2, 1);  // -2x
    p1.addTerm(1, 0);  // 1

    p2.addTerm(1, 2);  // x^2
    p2.addTerm(2, 1);  // 2x
    p2.addTerm(-1, 0);  // -1

    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;

    // Test addition
    result = p1 + p2;
    std::cout << "p1 + p2 = " << result << std::endl;

    // Test subtraction
    result = p1 - p2;
    std::cout << "p1 - p2 = " << result << std::endl;

    // Test multiplication
    result = p1 * p2;
    std::cout << "p1 * p2 = " << result << std::endl;

    // Test adding term with existing exponent
    p1.addTerm(2, 2);  // Should combine with existing 3x^2
    std::cout << "p1 after adding 2x^2: " << p1 << std::endl;

    // Test adding term with zero coefficient
    p1.addTerm(0, 3);  // Should not add this term
    std::cout << "p1 after adding 0x^3: " << p1 << std::endl;

    return 0;
}