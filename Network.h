#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Node.h"
#include <vector>
#include <memory>
using namespace std;

namespace neural {
  class Network {
  public:
    /**
     * Construct a new Neural Network.
     * @param input the number of input neurons
     * @param output the number of output neurons
     * @param hidden an optional vector containing the number of neurons for each hidden layer
     */
    Network(int input, int output, vector<int> hidden = NULL);
    /**
     * Train the net with a single test case
     * @return the error for this case after back propagation
     */
    double trainSingle(vector<double> input, vector<double> output);
    //! Convenience function to train a lot of cases at once
    double train(vector<vector<double> > input, vector<vector<double> > output);

    /**
     * Run the neural network for the given input
     */
    vector<double> run(vector<double> input);
  private:
    //! Input layer just consists of data
    vector<double> inputLayer;
    // Layers in between are accessed via prev and next pointers
    shared_ptr<Layer> firstHidden;
    shared_ptr<Layer> output;
    double calculateError();
  };
}

#endif
