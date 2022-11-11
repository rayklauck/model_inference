#ifndef MODEL_INFERENCE_STUDY_RANDOMPATTERNGENERATOR_HPP
#define MODEL_INFERENCE_STUDY_RANDOMPATTERNGENERATOR_HPP

#include <vector>
#include "random_ex.hpp"

class RandomPatternGenerator {

    int num_precomputed = 0;
    std::vector<bool> table;

    double one_prob;
    RandomGenerator R;

public:
    RandomPatternGenerator(double p): one_prob(p) {};

    bool operator() (int n) {
        if (n + 1 >= num_precomputed) {
            for (int i = 0; i <= n; i++) {
                table.push_back(R.random_bool(one_prob));
            }
        }

        return table.at(n);
    }
};

#endif //MODEL_INFERENCE_STUDY_RANDOMPATTERNGENERATOR_HPP
