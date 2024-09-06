#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

class Complex {
private:
    double real;
    double image;
public:
    Complex();
    Complex(double, double);
    double getReal() const;
    double getImage() const;
    double getAbs() const;
    friend Complex operator+ (const Complex&, const Complex&);
    friend Complex operator- (const Complex&, const Complex&);
    friend Complex operator* (const Complex&, const Complex&);
    friend Complex operator/ (const Complex&, const Complex&);
    friend std::ostream& operator<< (std::ostream&, const Complex&);
};

#endif