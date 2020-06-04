#include<utility>

#include "RegressionModels.hpp"


using namespace Model;

Linear_Regression::Linear_Regression(Matrix data, Matrix results,model_names model_name = model_names::polynomial, regularization reg = std::make_pair(regularization_type::empty, regularization_term {0} )){
    Matrix transformed_data;
    _model_name=model_name;

    // Transforms the data accordingly
    if (model_name == model_names::x) {
        transformed_data=Allx(data);
    } else if (model_name == model_names::polynomial) {
        transformed_data=Polynomial(data);
    } else {
        // Panic
    }
        

    // According to the regularization, find the weights
    if (reg.first == regularization_type::empty) {
        weights=((transformed_data.Transpose()*transformed_data).Inverse())*(transformed_data.Transpose())*results;
    }
    else if (reg.first == regularization_type::integer) {
        long reg_term= reg.second.reg_int;
        Matrix temp=transformed_data.Transpose()*transformed_data;
        //assuming temp will be square matrix
        Matrix identity(temp.ColumnSize());
        identity=identity*reg_term;
        weights=((identity+temp).Inverse())*transformed_data.Transpose()*results;
    } else {
        // TODO: Regularization_type == real
    }
}

Matrix Linear_Regression::Predict(Matrix X){
    Matrix transformed_X;
    if (_model_name == model_names::x) {
        transformed_X=Allx(X);
    } else if (_model_name == model_names::polynomial){
        transformed_X=Polynomial(X);
    }
    
    return weights.Transpose() * transformed_X;
}

Matrix Linear_Regression::Allx(Matrix x){
    return x;
}

Matrix Linear_Regression::Polynomial(Matrix x){
    Matrix y(x.matris());
    for(int i=0;i<y.RowSize();i++){
        int exp=1;
        for(int j=0;j<y.ColumnSize();j++){
            y[i][j]=pow(y[i][j],exp);
            exp++;
        }
    }    
    return y;
}
