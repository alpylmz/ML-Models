#include "RegressionModels.hpp"

int main(){
    std::vector<std::vector<double>> data1={{0},{1},{2},{3},{-1},{0},{-1.2}};
    std::vector<std::vector<double>> outputs1={{0},{1},{2},{3},{0.5},{0.2},{-1.5}};

    //TEST 1
    Linear_Regression model1(data1,outputs1,"x","empty");
    std::vector<std::vector<double>> x1={{100}};
    std::cout << model1.Predict(x1);
}