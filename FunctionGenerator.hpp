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
    int recursion_degree;
    std::vector<int> generator_functions_indx;
    std::vector<int> generator_functions_coeffs;
    std::function<bool(int)> f = [](int) { return 0; };

    int num_precomputed = 0;
    std::vector<bool> precomputed;

public:

    RandomFunction(int max_generator_functions, int min_coeff, int max_coeff, int max_recursion_degree) {
        RandomGenerator R;

        recursion_degree = R.random_integer(0, max_recursion_degree + 1);

        num_generator_functions = R.random_integer(1, max_generator_functions + 1);

        int t;
        for (int i = 0; i < num_generator_functions; i++) {
            t = R.random_integer(min_coeff, max_coeff + 1);
            generator_functions_coeffs.push_back(t);
            generator_functions_indx.push_back(R.random_integer(0, num_generator_functions));
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
