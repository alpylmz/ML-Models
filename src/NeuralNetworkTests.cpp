#include "NeuralNetworks.hpp"

int main(){
    std::vector<long> layer={2,4,4,1};
    Neural_Networks nn(layer,0.001);

    std::vector<std::vector<double>> data{{1,0},{0,0},{0,1},{1,1}};
    std::vector<double> ys{1,0,1,1};
    

    nn.Fit(data,ys);
    std::vector<double> ans=nn.Predict({0,0});
    std::cout << "answer pls be close to 100 ....   " << ans[0] << std::endl;
    return 0;
}