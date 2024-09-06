#include "matrix.h"
#include <cassert>

template<class item>
Matrix<item>::Matrix(const int& r, const int& c) : row(r), col(c), elements(r, std::vector<item>(c)) {}

template<class item>
Matrix<item>::Matrix(const Matrix& other) : row(other.row), col(other.col), elements(other.elements) {}

template<class item>
Matrix<item>& Matrix<item>::operator=(const Matrix& other) {
    if (this != &other) {
        row = other.row;
        col = other.col;
        elements = other.elements;
    }
    return *this;
}

template<class item>
item& Matrix<item>::operator()(const int& i, const int& j) {
    if (i < 0 || i >= row || j < 0 || j >= col) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return elements[i][j];
}

template<class item>
const item& Matrix<item>::operator()(const int& i, const int& j) const {
    if (i < 0 || i >= row || j < 0 || j >= col) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return elements[i][j];
}

template<class item>
void Matrix<item>::print() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << elements[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
