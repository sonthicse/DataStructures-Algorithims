#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "list.h"
#include <iostream>

class Polynomial;

class Term {
public:
    friend class Polynomial;
    Term() : coefficient(0), exponent(0) {}
    Term(const double& coef, const int& expo) : coefficient(coef), exponent(expo) {}

    void coef(const double& coef) { coefficient = coef; }
    void expo(const int& expo) { exponent = expo; }
    double coef() const { return coefficient; }
    int expo() const { return exponent; }

private:
    double coefficient;
    int exponent;
};

class Polynomial {
public:
    Polynomial();
    Polynomial(const Polynomial&);

    list<Term> getTerms() const { return terms; }
    
    Polynomial& operator=(const Polynomial&);
    Polynomial operator+(const Polynomial&);
    Polynomial operator-(const Polynomial&);
    Polynomial operator*(const Polynomial&);

    void addTerm(double coef, int expo);
    void simplify();
    void sort();

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

private:
    list<Term> terms;
};

#include "polynomial.cpp"

#endif