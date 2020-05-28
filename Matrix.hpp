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
        Matrix();

        Matrix(std::vector<std::vector<double>>);

        Matrix(long);

        Matrix(long column_size,long row_size);

        long ColumnSize();

        long RowSize();

        Matrix Transpose();

        double Determinant();

        double Cofactor(long x,long y);

        Matrix Minor(long x,long y);

        Matrix Inverse();

        Matrix operator+(const Matrix&);

        Matrix operator+(double);

        Matrix operator*(const Matrix&);

        Matrix operator*(double);

        std::vector<std::vector<double>> matris();

        std::vector<double> operator[](long);

        friend std::ostream& operator<<(std::ostream&,const Matrix&);

};