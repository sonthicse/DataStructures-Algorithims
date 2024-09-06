#include "polynomial.h"
#include <algorithm>
#include <cmath>

Polynomial::Polynomial() {}

Polynomial::Polynomial(const Polynomial& poly) {
    list_iterator<Term> it(poly.terms);
    for (it.Start(); it.Valid(); it.Advance()) {
        terms.Append(it.Current());
    }
}

Polynomial& Polynomial::operator=(const Polynomial& poly) {
    if (this != &poly) {
        terms = list<Term>();  // Clear current terms
        list_iterator<Term> it(poly.terms);
        for (it.Start(); it.Valid(); it.Advance()) {
            terms.Append(it.Current());
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& poly) {
    Polynomial result = *this;
    list_iterator<Term> it(poly.terms);
    for (it.Start(); it.Valid(); it.Advance()) {
        result.addTerm(it.Current().coef(), it.Current().expo());
    }
    result.simplify();
    result.sort();
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& poly) {
    Polynomial result = *this;
    list_iterator<Term> it(poly.terms);
    for (it.Start(); it.Valid(); it.Advance()) {
        result.addTerm(-it.Current().coef(), it.Current().expo());
    }
    result.simplify();
    result.sort();
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& poly) {
    Polynomial result;
    list_iterator<Term> it1(terms);
    for (it1.Start(); it1.Valid(); it1.Advance()) {
        list_iterator<Term> it2(poly.terms);
        for (it2.Start(); it2.Valid(); it2.Advance()) {
            double newCoef = it1.Current().coef() * it2.Current().coef();
            int newExpo = it1.Current().expo() + it2.Current().expo();
            result.addTerm(newCoef, newExpo);
        }
    }
    result.simplify();
    result.sort();
    return result;
}

void Polynomial::addTerm(double coef, int expo) {
    if (std::abs(coef) > 1e-10) {  // Ignore terms with very small coefficients
        terms.Append(Term(coef, expo));
        simplify();
        sort();
    }
}

void Polynomial::simplify() {
    list<Term> newTerms;
    list_iterator<Term> it(terms);
    for (it.Start(); it.Valid(); it.Advance()) {
        bool found = false;
        list_iterator<Term> newIt(newTerms);
        for (newIt.Start(); newIt.Valid(); newIt.Advance()) {
            if (newIt.Current().expo() == it.Current().expo()) {
                double newCoef = newIt.Current().coef() + it.Current().coef();
                if (std::abs(newCoef) > 1e-10) {
                    newIt.Current().coef(newCoef);
                } else {
                    newIt.Remove();
                }
                found = true;
                break;
            }
        }
        if (!found && std::abs(it.Current().coef()) > 1e-10) {
            newTerms.Append(it.Current());
        }
    }
    terms = newTerms;
}

void Polynomial::sort() {
    // Bubble sort implementation
    int n = terms.Length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (terms.Element(j).expo() < terms.Element(j + 1).expo()) {
                Term temp = terms.Element(j);
                terms.Element(j) = terms.Element(j + 1);
                terms.Element(j + 1) = temp;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    bool first = true;
    list_iterator<Term> it(poly.terms);
    for (it.Start(); it.Valid(); it.Advance()) {
        double coef = it.Current().coef();
        int expo = it.Current().expo();
        
        if (coef == 0) continue;
        
        if (!first && coef > 0) os << "+";
        if (coef == -1 && expo != 0) os << "-";
        else if (coef != 1 || expo == 0) os << coef;
        
        if (expo > 0) {
            os << "x";
            if (expo > 1) os << "^" << expo;
        }
        
        first = false;
    }
    if (first) os << "0";  // If polynomial is empty, print 0
    return os;
}