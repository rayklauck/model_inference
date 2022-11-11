#include <iostream>
#include <stdlib.h>
#include "FunctionGenerator.hpp"



using namespace std;
//using func =  RandomFunction;

int main() {

    // dummy func
    RandomFunction f(2);

    //auto f = [](int n){return 1;};

    const unsigned iterations = 5;
    const unsigned digits_per_iteration = 6;
    const unsigned digits_to_guess = 3;

    int n = 0;
    for (int i = 0; i<iterations; i++){
        //system("Color E4");
        n+=digits_per_iteration;
        for (int j = 0; j<n; j++){
            cout << f(n);
        }
        cout << "\nGuess next "<< digits_to_guess << " Digits: ";
        string user_input;
        cin >> user_input;
        int plus = 0;

        for (int k = 0; k<user_input.size(); k++){

            if (user_input.at(k)=='0' or user_input.at(k)=='1'){
                plus ++;
                bool prediction = (user_input.at(k) == '1');
                if (prediction == f(n+plus)){
                    cout << "correct ";
                } else {
                    cout << "false ";
                }
            }
        }
        cout << "\n\n";

    }



    return 0;
}
