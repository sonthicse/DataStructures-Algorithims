#include "Complex.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    Complex a(1, 2), b(3, 4), c;
    c = a + b;
    cout << c;
    c = a - b;
    cout << c;
    c = a * b;
    cout << c;
    c = a / b;
    cout << c;
}

Complex::Complex() : real(0), image(0) {}

Complex::Complex(double real, double image) {
    this->real = real;
    this->image = image;
}

double Complex::getReal() const { return real; }

double Complex::getImage() const { return image; }

double Complex::getAbs() const {
    double abs;
    abs = sqrt(pow(real, 2) + pow(image, 2));
    return abs;
}

Complex operator+ (const Complex& complex1, const Complex& complex2) {
    Complex complex(complex1.real + complex2.real, complex1.image + complex2.image);
    return complex;
}

Complex operator- (const Complex& complex1, const Complex& complex2) {
    Complex complex(complex1.real - complex2.real, complex1.image - complex2.image);
    return complex;
}

Complex operator* (const Complex& complex1, const Complex& complex2) {
    Complex complex(complex1.real*complex2.real - complex1.image*complex2.image, complex1.real*complex2.image + complex2.real*complex1.image);
    return complex;
}

Complex operator/ (const Complex& complex1, const Complex& complex2) {
    Complex complex((complex1.real*complex2.real + complex1.image*complex2.image)/(pow(complex1.image, 2) + pow(complex2.image, 2)), (complex1.image*complex2.real - complex1.real*complex2.image)/(pow(complex1.image, 2) + pow(complex2.image, 2)));
    return complex;
}

std::ostream& operator<< (std::ostream& os, const Complex& complex) {
    return os << complex.real << "+" << complex.image << "i\n";
}