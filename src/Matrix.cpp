#include "Matrix.hpp"

Matrix::Matrix(){
    _column_size=0;
    _row_size=0;
}

Matrix::Matrix(long column_size,long row_size){
    _column_size=column_size;
    _row_size=row_size;

    _matrix.resize(_row_size);
    for(int i=0;i<_row_size;i++){
        _matrix[i].resize(_column_size);
    }
}

Matrix::Matrix(long size){
    _column_size=size;
    _row_size=size;

    _matrix.resize(size);
    for(int i=0;i<_matrix.size();i++)
        _matrix[i].resize(size);

    //Constructing identity matrix
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j)
                _matrix[i][j]=1;
            else
                _matrix[i][j]=0;
        }
    }

    
}

Matrix::Matrix(std::vector<std::vector<double>> matrix){
    _matrix=matrix;
    _column_size=_matrix[0].size();//This would cause a bug, I am assuming that _matrix is not empty
    _row_size=_matrix.size();
}

long Matrix::ColumnSize(){
    return _column_size;
}

long Matrix::RowSize(){
    return _row_size;
}

Matrix Matrix::operator+(const Matrix& rhs){
    if(_column_size!=rhs._column_size || _row_size!=rhs._row_size){
        throw MatrixSize();
    }

    Matrix new_one(_matrix);

    for(int i=0;i<_row_size;i++){
        for(int j=0;j<_column_size;j++){
            new_one._matrix[i][j]+=rhs._matrix[i][j];
        }
    }
    return new_one;
}

Matrix Matrix::operator+(double val){
    Matrix new_one(_matrix);

    for(int i=0;i<_row_size;i++){
        for(int j=0;j<_column_size;j++){
            new_one._matrix[i][j]+=val;
        }
    }

    return new_one;
}

Matrix Matrix::operator*(const Matrix& rhs){
    if(_column_size!=rhs._row_size)
        throw MatrixSize();

    Matrix new_one(rhs._column_size,_row_size);
    
    for(int i=0;i<_row_size;i++){
        for(int j=0;j<rhs._column_size;j++){
            for(int k=0;k<_column_size;k++){
                new_one._matrix[i][j] += _matrix[i][k] * rhs._matrix[k][j];
            }
        }
    }
    
    return new_one;
}

Matrix Matrix::operator*(double val){
    Matrix new_one(_matrix);
    new_one._column_size=_column_size;
    new_one._row_size=_row_size;

    for(int i=0;i<_row_size;i++){
        for(int j=0;j<_column_size;j++){
            new_one._matrix[i][j]*=val;
        }
    }

    return new_one;

}

std::vector<double> Matrix::operator[](long x){
    return _matrix[x];
}

Matrix Matrix::Transpose(){
    //Creating a new vector to take transpose
    std::vector<std::vector<double>> new_matrix;
    new_matrix.resize(_column_size);
    for(int i=0;i<_column_size;i++){
        new_matrix[i].resize(_row_size);
    }

    // Assigning values for new matrix
    for(int i=0;i<_row_size;i++){
        for(int j=0;j<_column_size;j++){
            new_matrix[j][i]=_matrix[i][j];
        }
    }

    //Constructing new matrix from the vector
    Matrix result(new_matrix);
    return result;
}

Matrix Matrix::Minor(long x, long y){
    //x is row, y is column
    Matrix new_matrix(_matrix);

    //Deleting the unwanted parts
    new_matrix._matrix.erase(new_matrix._matrix.begin()+x);
    for(int i=0;i<new_matrix._matrix.size();i++){
        new_matrix._matrix[i].erase(new_matrix._matrix[i].begin()+y);
    }

    new_matrix._column_size--;
    new_matrix._row_size--;
    return new_matrix;
}

double Matrix::Cofactor(long x,long y){
    return pow(-1,x+y)*(Minor(x,y).Determinant());
}

double Matrix::Determinant(){
    if(_column_size==1 && _row_size==1)
        return _matrix[0][0];

    double det=0;
    for(int i=0;i<_column_size;i++){
        //std::cout << Cofactor(0,i) <<" " << _matrix[0][i] << std::endl;
        det += (Cofactor(0,i) * _matrix[0][i]);
    }
    return det;
}

Matrix Matrix::Inverse(){
    if(_column_size==1 && _row_size==1){
        // Creating a 1x1 matrix and the only value is 1/_matrix[0][0]
        Matrix x(1,1);
        x._matrix[0][0]=1/_matrix[0][0];
        return x;
    }

    double det=Determinant();
    if(det==0)
        throw DoNotHaveInverseError();
    
    std::vector<std::vector<double>> cofactor_matrix;
    cofactor_matrix.resize(_row_size);
    for(int i=0;i<_row_size;i++){
        cofactor_matrix[i].resize(_column_size);
    }

    for(int i=0;i<_row_size;i++){
        for(int j=0;j<_column_size;j++){
            cofactor_matrix[i][j]=Minor(i,j).Determinant();
            cofactor_matrix[i][j]/=det;
        }
    }

    Matrix new_matrix(cofactor_matrix);
    new_matrix=new_matrix.Transpose();
    return new_matrix;
}

std::vector<std::vector<double>> Matrix::matris(){
    return _matrix;
}


double Matrix::Dot(Matrix x){
    // There is no control if they are not vectors or not, this function directly computes dot product
    // with using Matrix[0]
    double sum=0;
    for(int i=0;i<ColumnSize();i++){
        sum+=_matrix[0][i]*x[0][i];
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
    for(int i=0;i<rhs._row_size;i++){
        for(int j=0;j<rhs._column_size;j++){
            os << rhs._matrix[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}
