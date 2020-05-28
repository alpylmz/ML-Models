#include <vector>
#include <math.h>
#include <iostream>

#include "Exception.hpp"

class Matrix{
    private:
        std::vector<std::vector<double>> _matrix;
        long _column_size;
        long _row_size;

    public:
        // Default constructor
        // Gives column size and row size 0
        Matrix();

        // This constructor takes the matrix as input and sets the _matrix, _column_size and _row_size accordingly
        Matrix(std::vector<std::vector<double>> matrix);

        // This constructor constructs an identity matrix, size x size
        Matrix(long size);

        // This constructor allocates for _matrix accordingly
        Matrix(long column_size,long row_size);

        // This function returns _column_size
        long ColumnSize();

        // This function returns _row_size
        long RowSize();

        Matrix Transpose();

        double Determinant();

        double Cofactor(long x,long y);

        Matrix Minor(long x,long y);

        // Taking the inverse of a matrix
        // If determinant is 0, throws DoNotHaveInverseError()
        Matrix Inverse();

        // Adds two matrices bitwise
        // If sizes do not match, throws exception MatrixSize()
        Matrix operator+(const Matrix&);

        // Adds val to every value of _matrix
        Matrix operator+(double val);

        // Normal matrix multiplication
        // If sizes do not comply, throws exception MatrixSize()
        Matrix operator*(const Matrix&);

        // Multiplies every value with val
        Matrix operator*(double val);

        // This function returns _matrix
        std::vector<std::vector<double>> matris();

        // This function return _matrix[x]
        std::vector<double> operator[](long x);

        // Output format is 
        // 0 1 2 
        // 3 4 5
        // 1.2 3.5 6.9
        //
        friend std::ostream& operator<<(std::ostream&,const Matrix&);

};