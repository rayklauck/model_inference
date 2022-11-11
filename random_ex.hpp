//
// Created by Linus on 11.11.2022.
//

#ifndef MODEL_INFERENCE_RANDOM_EX_HPP
#define MODEL_INFERENCE_RANDOM_EX_HPP

#include <random>

class RandomGenerator {
public:

    int random_integer(int from, int to) {
        std::random_device rd;
        std::mt19937 mt(rd());

        std::uniform_int_distribution<int> d(from, to);

        return d(mt);
    }

    double random_double_unit() {
        std::random_device rd;
        std::mt19937 mt(rd());

        std::uniform_real_distribution<double> d(0.0, 1.0);

        return d(mt);
    }

    int random_bool(double one_prob) {
        std::random_device rd;
        std::mt19937 mt(rd());

        std::uniform_real_distribution<double> dist_unit(0.0, 1.0);

        return dist_unit(mt) <= one_prob ? 1 : 0;
    }
};


#endif //MODEL_INFERENCE_RANDOM_EX_HPP
