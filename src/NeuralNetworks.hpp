#include "Matrix.hpp"
#include "Models.hpp"
#include <math.h>



/*TO DO:
 * Stronger tests
 * Much cleaner implementation with Matrix class
 * Manipulation of epoch number
 * = operator overloading
*/
class Neural_Networks{
    private:
        //holds how many unit are there in each corresponding layer
        //starts from input layer to output layer
        std::vector<long> layer_info;

        //the first vector separates the weights according to their layers
        //weights[0] consists of first layer weights
        //weights[0][0] consists of first layer first neuron's weights
        //be careful that output layer will have no weight
        std::vector<std::vector<std::vector<double>>> weights;

        double learning_rate;

        std::vector<std::vector<double>> forward_propagate(std::vector<double> inputn);

        void back_propagate(std::vector<double> output_deltas, std::vector<std::vector<double>> activation);


    public:

        //This constructor takes the number of layers
        Neural_Networks(std::vector<long> layers,double learningrate);

        std::vector<double> Predict(std::vector<double> input);

        void Fit(std::vector<std::vector<double>> data,std::vector<double> ans);


};