#include "Matrix.hpp"

class Linear_Regression{
    private:
        Matrix weights;
        std::string _model_name;
        std::string _regularization;

        Matrix Allx(Matrix);
        Matrix Polynomial(Matrix);

    public:
        Linear_Regression(Matrix data, Matrix outputs,std::string model_name,std::string regularization);

        Matrix Predict(Matrix X);
};