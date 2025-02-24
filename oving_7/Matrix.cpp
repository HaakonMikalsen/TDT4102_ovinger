#include "Matrix.h"

#include <iostream>
// BEGIN: 2b

// END: 2b

// BEGIN: 2c
double Matrix::get(int row, int col) const {
    // std::cout << col + row*collums <<":"<<matrix[(col + row*collums)];
    return matrix[(col + row * columns)];
}
void Matrix::set(int row, int col, double value) {
    matrix[col + row * columns] = value;
}
// END: 2c

// Her kan du gjøre 2d (frivillig):

// BEGIN: 2f
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        os << "|";
        for (int j = 0; j < m.columns; j++) {
            os << m.get(i, j);
            os << " , ";
        }
        os << "|" << std::endl;
    }
    return os;
}
// END: 2f

// BEGIN: 4a
Matrix::Matrix(const Matrix& rhs) {
    rows = rhs.getRows();
    columns = rhs.getColumns();
    matrix = new double[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[(j + i * columns)] = rhs.get(i, j);
        }
    }
}
// END: 4a

// BEGIN: 4b
Matrix& Matrix::operator=(const Matrix& rhs) {
    rows = rhs.getRows();
    columns = rhs.getColumns();
    matrix = new double[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[(j + i * columns)] = rhs.get(i, j);
        }
    }
    return *this;
}

// END: 4b

// BEGIN: 5a

Matrix& Matrix::operator+=(const Matrix& rhs){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[(j + i * columns)] += rhs.get(i, j);
        }
    }
    return *this;
}   

// END: 5a

// BEGIN: 5b
Matrix Matrix::operator+(const Matrix& rhs){
    Matrix resultMatrix(*this);
    resultMatrix+= rhs;
    return resultMatrix;
}

// END: 5b

void testMatrix() {
    // Her kan du teste løsningen din (oppgave 5c):
}

// Her kan du gjøre 5d (frivillig):