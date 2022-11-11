#ifndef MODEL_INFERENCE_STUDY_FUNCTIONGENERATOR_HPP
#define MODEL_INFERENCE_STUDY_FUNCTIONGENERATOR_HPP

#include <functional>
#include "random_ex.hpp"
#include <vector>
#include <cmath>

int num_generator_functions = 3;
std::function<bool(int)> generator_functions[] = {[] (int n) {return ((int) std::sin(n)) % 2;},
                                                  [] (int n) {return (n * n) % 2;},
                                                  [] (int n) {return n % 2;}};

class RandomFunction {
    int num_generator_functions;
    std::vector<int> generator_functions_indx;

    int num_precomputed = 0;
    std::vector<bool> precomputed;

public:

    RandomFunction(int max_generator_functions) {
        RandomGenerator R;

        num_generator_functions = R.random_integer(1, max_generator_functions);

        for (int i = 0; i < num_generator_functions; i++) {
            generator_functions_indx.push_back(R.random_integer(0, num_generator_functions - 1));
        }
    }

    bool operator()(int n) {
        if (n + 1 >= num_precomputed) {

            bool b = false;
            for (int i = num_precomputed; i <= n; i++) {

                for (int j = 0; j < num_generator_functions; j++) {
                    b = b || generator_functions[generator_functions_indx[j]](n);
                }

                precomputed.push_back(b);
            }


            return precomputed.at(n);
        };
    }
};


#endif //MODEL_INFERENCE_STUDY_FUNCTIONGENERATOR_HPP
