#include "Matrix.hpp"

int main(){
    std::vector<std::vector<double>> test_matrix;
    test_matrix.push_back({1,2});
    test_matrix.push_back({3,4});

    Matrix matrix(test_matrix);

    std::vector<std::vector<double>> test_matrix2;
    test_matrix2.push_back({3,2});
    test_matrix2.push_back({1,0});

    Matrix matrix2(test_matrix2);

    //TEST 1
    std::cout << "Test 1: Print" << std::endl;
    std::cout << matrix;

    //TEST 2
    std::cout << "Test 2: Transpose" << std::endl;
    std::cout << matrix.Transpose();

    //TEST 3
    std::cout << "Test 3: Column and row sizes" << std::endl;
    std::cout << matrix.ColumnSize() << " " << matrix.RowSize() << std::endl;

    //TEST 4
    std::cout << "Test 4: + operator" << std::endl;
    std::cout << matrix+matrix2;

    //TEST 5
    std::cout << "Test 5: + operator" << std::endl;
    std::cout << matrix+100;

    //TEST 6
    std::cout << "Test 6: * operator" << std::endl;
    std::cout << matrix*matrix2;

    //TEST 7
    std::cout << "Test 7: * operator" << std::endl;
    std::cout << matrix*100;

    //TEST 8
    std::cout << "Test 8: Minor" << std::endl;
    std::cout << matrix.Minor(0,0);

    //TEST 9
    std::cout << "Test 9: Cofactor" << std::endl;
    std::cout << matrix.Cofactor(0,1) << std::endl;
    
    //TEST 10
    std::cout << "Test 10: Determinant" << std::endl;
    std::cout << matrix.Determinant() << std::endl;

    //TEST 11
    std::cout << "Test 11: Inverse" << std::endl;
    std::cout << matrix.Inverse();

    return 0;
}