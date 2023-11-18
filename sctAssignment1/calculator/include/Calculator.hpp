#pragma once

#include <iostream>
#include <cmath>

template<typename T>

class Calculator{
    public:

        Calculator(){};

        void addition(T first, T second){
            std::cout << first + second << std::endl;
        }

        void substraction(T first, T second){
            std::cout << first - second << std::endl;
        }

        void multiplication(T first, T second){
            std::cout << first * second << std::endl;
        }

        void division(T first, T second){
            if(second == 0) std::cout << "You can not divide a number to zero !!!" << std::endl;
            else std::cout << first / second << std::endl;
        }

        void square(T number){
            std::cout << number * number << std::endl;
        }

        void exponentiation(T first, T second){
            std::cout << pow(first,second) << std::endl;
        }

        void modulus(T first, T second){
            std::cout << first % second << std::endl;
        }
};