#include "NeuralNetworks.hpp"

Neural_Networks::Neural_Networks(std::vector<long> layers,double learningrate){
    layer_info=layers;
    learning_rate=learningrate;
    //initialize weights
    //put all of them 0.1
    
    //TO DO: MAKE IT RANDOMIZE
    
    //first resize layer
    weights.resize(layer_info.size());
    for(int i=0;i<(weights.size()-1);i++){
        weights[i].resize(layer_info[i]);
        for(int j=0;j<weights[i].size();j++){
            weights[i][j].resize(layer_info[i+1]);
            for(int k=0;k<weights[i][j].size();k++){
                weights[i][j][k]=0.1;
            }
        }
    }
}

std::vector<std::vector<double>> Neural_Networks::forward_propagate(std::vector<double> inputn){
    //activation[layer][neuron]
    std::vector<std::vector<double>> activation;
    activation.resize(layer_info.size());
    for(int i=0;i<activation.size();i++){
        activation[i].resize(layer_info[i]);
    }

    //putting inputs
    for(int i=0;i<layer_info[0];i++){
        activation[0][i]=tanh(inputn[i]);
    }

    for(int i=1;i<layer_info.size();i++){//iterating layers, except input layer and output layer
        for(int j=0;j<layer_info[i];j++){//here, find what is the activation value of ith layers jth neuron
            activation[i][j]=0;
            for(int k=0;k<layer_info[i-1];k++){//the previous layer's neurons
                activation[i][j]+=activation[i-1][k]*weights[i-1][k][j];
            }
            //TO LOOK: DO WE APPLY TANH TO OUTPUT LAYERS?
            if(i!=layer_info.size()-1){
                activation[i][j]=tanh(activation[i][j]); //applying h function
            }
        }
    }

    return activation;
}

void Neural_Networks::back_propagate(std::vector<double> output_deltas,std::vector<std::vector<double>> activation){
    std::vector<std::vector<double>> delta;
    delta.resize(layer_info.size());
    for(int i=0;i<delta.size();i++){
        delta[i].resize(layer_info[i]);
    }

    //putting inputs
    for(int i=0;i<delta.size();i++){
        for(int j=0;j<delta[i].size();j++){
            delta[i][j]=0;
        }
    }

    for(int i=0;i<layer_info[layer_info.size()-1];i++){//output layer
        delta[layer_info.size()-1][i]=output_deltas[i]*(1-activation[layer_info.size()-1][i]*activation[layer_info.size()-1][i]);
    }

    for(int i=layer_info.size()-1;i>0;i--){//start from output layer -1, until input layers, ith layer
        for(int j=0;j<layer_info[i];j++){// jth neuron
            for(int k=0;k<layer_info[i+1];k++){//k is the next layer's neuron
                delta[i][j]+=weights[i][j][k]*delta[i+1][k];
            }
            delta[i][j]*=(1-activation[i][j]*activation[i][j]);
        }
    }

    //after here, find the derivatives of w_{ij} and update correspondingly

    for(int i=0;i<layer_info.size()-1;i++){//ith layer, this should not come to output layer
        for(int j=0;j<layer_info[i];j++){//ith layer's jth neuron
            for(int k=0;k<weights[i][j].size();k++){//here, weights[i][j][k] is w_{jk}
                //here delta[i+1][k]*activation[i][j] is the derivative
                //std::cout << delta[i+1][k] << std::endl;
                weights[i][j][k]+=delta[i+1][k]*activation[i][j];
                
            }
        }
    }
    return;
}


void Neural_Networks::Fit(std::vector<std::vector<double>> data,std::vector<double> ans){
    for(int epoch=0;epoch<10000;epoch++){
        for(int i=0;i<data.size();i++){
            //for every input comes here, first forward propagate, then back propagate
            std::vector<std::vector<double>> activation = forward_propagate(data[i]);
            
            //now need to find output deltas, activation[activation.size()-1]-ans
            std::vector<double> output_deltas;
            output_deltas.resize(ans.size());
            for(int j=0;j<ans.size();j++){
                output_deltas[j]=-ans[j]-activation[activation.size()-1][j];
            }
            //std::cout << "cost is " << output_deltas[0] << std::endl;
            //just backpropagate
            back_propagate(output_deltas,activation);
        }
    }
    return;
}

std::vector<double> Neural_Networks::Predict(std::vector<double> input){
    std::vector<std::vector<double>> activation=forward_propagate(input);
    
    return activation[activation.size()-1];
}