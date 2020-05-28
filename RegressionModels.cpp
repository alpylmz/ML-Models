#include "RegressionModels.hpp"

Linear_Regression::Linear_Regression(Matrix data, Matrix results,std::string model_name="polynomial",std::string regularization_term="empty"){
    Matrix transformed_data;
    _model_name=model_name;

    // Transforms the data accordingly
    if(model_name=="x")
        transformed_data=Allx(data);
    else if(model_name=="polynomial")
        transformed_data=Polynomial(data);

    // According to the regularization, find the weights
    if(regularization_term=="empty"){
        weights=((transformed_data.Transpose()*transformed_data).Inverse())*(transformed_data.Transpose())*results;
    }
    else{
        long reg_term=std::stoi(regularization_term);
        Matrix temp=transformed_data.Transpose()*transformed_data;
        //assuming temp will be square matrix
        Matrix identity(temp.ColumnSize());
        identity=identity*reg_term;
        weights=((identity+temp).Inverse())*transformed_data.Transpose()*results;
    }
}

Matrix Linear_Regression::Predict(Matrix X){
    Matrix transformed_X;
    if(_model_name=="x")
        transformed_X=Allx(X);
    else if(_model_name=="polynomial"){
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