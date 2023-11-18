#include <iostream>
#include "../include/Calculator.hpp"

int main(){
    Calculator<int> merhaba;
    Calculator<float> merhaba2;
    Calculator<double> merhaba3;

    int type;

    while(true){
        std::cout << "Please enter a number for your calculation type.\n0-terminating the program\n1-int\n2-float\n3-double" << std::endl;
        std::cin >> type;
        if(type == 0) break;
        else if(type == 1){
            std::cout << "Which operation do you want to do ?\n0-terminating the program\n1-addition\n2-substraction\n3-multiplication\n4-division\n5-square\n6-exponentiation\n7-modulus" << std::endl;
            int operation;
            std::cin >> operation;
            if(operation == 0) break;
            else if(operation == 1){
                int first, second;
                std::cout << "Please enter two numbers for addition." << std::endl;
                std::cin >> first >> second;
                merhaba.addition(first,second);
            }
            else if(operation == 2){
                int first, second;
                std::cout << "Please enter two numbers for substraction." << std::endl;
                std::cin >> first >> second;
                merhaba.substraction(first,second);
            }
            else if(operation == 3){
                int first, second;
                std::cout << "Please enter two numbers for multiplication." << std::endl;
                std::cin >> first >> second;
                merhaba.multiplication(first,second);
            }
            else if(operation == 4){
                int first, second;
                std::cout << "Please enter two numbers for division." << std::endl;
                std::cin >> first >> second;
                if(second == 0) std::cout << "You can not divide a number to zero !!!" << std::endl;
                else merhaba.division(first,second);
            }
            else if(operation == 5){
                int number;
                std::cout << "Please enter a number for square." << std::endl;
                std::cin >> number;
                merhaba.square(number);
            }
            else if(operation == 6){
                int first, second;
                std::cout << "Please enter two numbers for exponentiation." << std::endl;
                std::cin >> first >> second;
                merhaba.exponentiation(first,second);
            }
            else if(operation == 7){
                int first, second;
                std::cout << "Please enter two numbers for modulus." << std::endl;
                std::cin >> first >> second;
                merhaba.modulus(first,second);
            }
            else std::cout << "Please enter a valid number !!!" << std::endl;
        }
        else if(type == 2){
            std::cout << "Which operation do you want to do ?\n0-terminating the program\n1-addition\n2-substraction\n3-multiplication\n4-division\n5-square\n6-exponentiation" << std::endl;
            int operation;
            std::cin >> operation;
            if(operation == 0) break;
            else if(operation == 1){
                float first, second;
                std::cout << "Please enter two numbers for addition." << std::endl;
                std::cin >> first >> second;
                merhaba2.addition(first,second);
            }
            else if(operation == 2){
                float first, second;
                std::cout << "Please enter two numbers for substraction." << std::endl;
                std::cin >> first >> second;
                merhaba2.substraction(first,second);
            }
            else if(operation == 3){
                float first, second;
                std::cout << "Please enter two numbers for multiplication." << std::endl;
                std::cin >> first >> second;
                merhaba2.multiplication(first,second);
            }
            else if(operation == 4){
                float first, second;
                std::cout << "Please enter two numbers for division." << std::endl;
                std::cin >> first >> second;
                if(second == 0) std::cout << "You can not divide a number to zero !!!" << std::endl;
                else merhaba2.division(first,second);
            }
            else if(operation == 5){
                float number;
                std::cout << "Please enter a number for square." << std::endl;
                std::cin >> number;
                merhaba2.square(number);
            }
            else if(operation == 6){
                float first, second;
                std::cout << "Please enter two numbers for exponentiation." << std::endl;
                std::cin >> first >> second;
                merhaba2.exponentiation(first,second);
            }
            else std::cout << "Please enter a valid number !!!" << std::endl;
        }
        else if(type == 3){
            std::cout << "Which opeartion do you want to do ?\n0-terminating the program\n1-addition\n2-substraction\n3-multiplication\n4-division\n5-square\n6-exponentiation" << std::endl;
            int operation;
            std::cin >> operation;
            if(operation == 0) break;
            else if(operation == 1){
                double first, second;
                std::cout << "Please enter two numbers for addition." << std::endl;
                std::cin >> first >> second;
                merhaba3.addition(first,second);
            }
            else if(operation == 2){
                double first, second;
                std::cout << "Please enter two numbers for substraction." << std::endl;
                std::cin >> first >> second;
                merhaba3.substraction(first,second);
            }
            else if(operation == 3){
                double first, second;
                std::cout << "Please enter two numbers for multiplication." << std::endl;
                std::cin >> first >> second;
                merhaba3.multiplication(first,second);
            }
            else if(operation == 4){
                double first, second;
                std::cout << "Please enter two numbers for division." << std::endl;
                std::cin >> first >> second;
                if(second == 0) std::cout << "You can not divide a number to zero !!!" << std::endl;
                else merhaba3.division(first,second);
            }
            else if(operation == 5){
                double number;
                std::cout << "Please enter a number for square." << std::endl;
                std::cin >> number;
                merhaba3.square(number);
            }
            else if(operation == 6){
                double first, second;
                std::cout << "Please enter two numbers for exponentiation." << std::endl;
                std::cin >> first >> second;
                merhaba3.exponentiation(first,second);
            }
            else std::cout << "Please enter a valid number !!!" << std::endl;
        }

        else std::cout << "Please enter a valid number !!!" << std::endl;
    }
    
    return 0;
}
