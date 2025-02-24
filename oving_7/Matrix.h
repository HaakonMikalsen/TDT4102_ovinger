#pragma once
#include <iostream>
#include <utility>

class Matrix {
   private:
    // BEGIN: 2a
    int rows;
    int columns;
    double* matrix;
    // END: 2a
   public:
    // BEGIN: 2b
    Matrix(int nRows, int nColumns) {
        rows = nRows;
        columns = nColumns;
        matrix = new double[rows*columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                // std::cout <<(j + i*colums)<<":";
                matrix[(j + i*columns)] = 0;
                // std::cout <<matrix[(j + i*colums)]<<std::endl;

            }
        }
        // std::cout <<matrix[4]<<std::endl;
    }
    explicit Matrix(int nRows){
        rows = nRows;
        columns = nRows;
        matrix = new double[rows*columns] {};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(j + i*columns)] = 0;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            matrix[i + i*columns] = 1;
        }
    }
    ~Matrix(){
        rows = 0;
        columns = 0;
        delete matrix;
        matrix = nullptr;
    }
    // END: 2b

    // BEGIN: 2c
    double get(int row, int col) const;
    void set(int row, int col, double value);
    // END: 2c

    // Her kan du gjøre 2d (frivillig):

    // BEGIN: 2e
    int getRows() const{
        return rows;
    }
    int getColumns() const{
        return columns;
    }
    // END: 2e
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    // BEGIN: 2f

    // END: 2f

    // BEGIN: 4a
    Matrix(const Matrix & rhs);
    // END: 4a

    // BEGIN: 4b
    Matrix& operator=(const Matrix& rhs);
    // END: 4b

    // BEGIN: 5a
    Matrix& operator+=(const Matrix& rhs);
    // END: 5a

    // BEGIN: 5b
    Matrix operator+(const Matrix& rhs);

    // END: 5b

    // Her kan du gjøre 5d (frivillig):
};


void testMatrix();
