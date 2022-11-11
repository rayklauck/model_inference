#ifndef MODEL_INFERENCE_STUDY_SIMPLEPATTERN_HPP
#define MODEL_INFERENCE_STUDY_SIMPLEPATTERN_HPP
//
// Created by ray on 11.11.22.
//
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include "random_ex.hpp"

using namespace std;

vector<string> patterns = {"011101","00110","10011","111010"};

//vector<function<int(int)>> a = {[](){}};

class SimplePattern{
public:
    string pattern;
    double flip_chance;
    RandomGenerator R;
    vector<bool> storage;

    SimplePattern(double flip_chance = 0): flip_chance(flip_chance){

        pattern = patterns[R.random_integer(0,(int) patterns.size()-1)];

    }



    bool operator()(int n){
        if (n >= storage.size()){
            for (int i = storage.size(); i<=n; i++){
                storage.push_back(call(i));
            }
        }
        return storage[n];
    }

    bool call(int n){
        bool res = pattern.at(n%pattern.size()) == '1';
        if (R.random_bool(flip_chance)){
            return !res;
        } else {
            return res;
        }
    }
};

#endif