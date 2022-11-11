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

    SimplePattern(){
        RandomGenerator R;
        pattern = patterns[R.random_integer(0,pattern.size()-1)];
    }

    bool operator()(int n){
        return pattern.at(n%pattern.size()) == '1';
    }
};