#include "Matrix.hpp"
#include "Models.hpp"

class Linear_Regression{
    private:
        Matrix weights;
        Model::model_names _model_name;
        Model::regularization _regularization;

        Matrix Allx(Matrix);
        Matrix Polynomial(Matrix);

    public:
        // This constructor takes data, outputs, model_name and regularization
        // If model_name is x, do not transforms the data
        // If model_name is polynomial, transforms the data as x+x^2+x^3+x^4+...
        // If you do not want to use regularization for your model, give regularization "empty"
        // Otherwise, give the regularization term
        Linear_Regression(Matrix data, Matrix outputs,Model::model_names model_name, Model::regularization regularization_term);

        Matrix Predict(Matrix X);
};
