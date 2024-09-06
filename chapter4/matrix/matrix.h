#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

template<class item>
class Matrix {
public:
    Matrix() : row(0), col(0) {}
    Matrix(const int& r, const int& c);
    Matrix(const Matrix&);
    ~Matrix() = default;
    Matrix& operator=(const Matrix&);
    int Row() const { return row; }
    int Col() const { return col; }
    item& operator()(const int& i, const int& j);
    const item& operator()(const int& i, const int& j) const;
    friend Matrix<item> operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.row != m2.row || m1.col != m2.col) {
            throw std::invalid_argument("Matrix dimensions do not match for addition");
        }
        Matrix<item> result(m1.row, m1.col);
        for (int i = 0; i < m1.row; ++i) {
            for (int j = 0; j < m1.col; ++j) {
                result(i, j) = m1(i, j) + m2(i, j);
            }
        }
        return result;
    }
    friend Matrix<item> operator-(const Matrix& m1, const Matrix& m2) {
        if (m1.row != m2.row || m1.col != m2.col) {
            throw std::invalid_argument("Matrix dimensions do not match for subtraction");
        }
        Matrix<item> result(m1.row, m1.col);
        for (int i = 0; i < m1.row; ++i) {
            for (int j = 0; j < m1.col; ++j) {
                result(i, j) = m1(i, j) - m2(i, j);
            }
        }
        return result;
    }
    friend Matrix<item> operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.col != m2.row) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }
        Matrix<item> result(m1.row, m2.col);
        for (int i = 0; i < m1.row; ++i) {
            for (int j = 0; j < m2.col; ++j) {
                result(i, j) = 0;
                for (int k = 0; k < m1.col; ++k) {
                    result(i, j) += m1(i, k) * m2(k, j);
                }
            }
        }
        return result;
    }
    void print() const;

private:
    int row;
    int col;
    std::vector<std::vector<item>> elements;
};

#include "matrix.cpp"

#endif