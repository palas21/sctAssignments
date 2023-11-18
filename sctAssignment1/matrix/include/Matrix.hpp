#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <string>

template<typename T>

class Matrix{
    public:
        Matrix(int row, int column, std::vector<std::vector<T>> matrix){
            this->row = row;
            this->column = column;
            this->matrix = matrix;
        }

        Matrix(const Matrix<T>& temp){
            this->row = temp.row;
            this->column = temp.column;
            this->matrix = temp.matrix;
        }

        Matrix(int row,int column){ // a constructor for all elements 0 matrix
            this->row = row;
            this->column = column;
            for(int i = 0; i < row; i++){
                std::vector<T> temp;
                for(int j = 0; j < column; j++){
                    temp.push_back(0);
                }
                matrix.push_back(temp);
            }
        }

        T trace(){ // we return the trace of the matrix
            T result = 0;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    if(i == j){
                        result += matrix[i][j];
                    }
                }
            }
            return result;
        }

        int determinant(){ // we find the determimnant of the matrix up to 3x3
            if(this->row != this->column) return 0;
            else if(this->row == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            else if(this->row == 3) return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
            else return 0;
        }

        void inverse(){ // we take the inverse of the matrix up to 3x3
            if(this->row == 2 && this->column == 2){
                T temp;
                T determinant = this->determinant();
                temp = matrix[0][0] / determinant;
                matrix[0][0] = matrix[1][1] / determinant;
                matrix[1][1] = temp;
                matrix[0][1] = -matrix[0][1] / determinant;
                matrix[1][0] = -matrix[1][0] / determinant;
            }
            else if(this->row == 3 && this->column == 3){ // take inverse of 3x3 matrix
                T temp;
                T determinant = this->determinant();
                temp = matrix[0][0] / determinant;
                matrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / determinant;
                matrix[1][1] = temp;
                matrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / determinant;
                matrix[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / determinant;
                matrix[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / determinant;
                matrix[2][1] = (matrix[0][1] * matrix[1][0] - matrix[0][0] * matrix[1][1]) / determinant;
                matrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / determinant;
                matrix[1][2] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / determinant;
                matrix[2][0] = (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) / determinant;
            }
            else{
                std::cout << "Inverse is not defined for this matrix" << std::endl;
            }
        }

        void transpose(){ //transpose the matrix
            Matrix<T> result(this->column,this->row);

            for(int i = 0; i < this->row; i++){
                for(int j = 0; j < this->column; j++){
                    result.matrix[j][i] = this->matrix[i][j];
                }
            }
            this->matrix = result.matrix;
        }

        Matrix operator+(const Matrix& second){
            if(this->row != second.row || this->column != second.column){
                std::cout << "Matrices are not compatible for addition" << std::endl;
                return *this;
            }
            else{
                Matrix<T> result(this->row,this->column);
                for(int i = 0; i < this->row; i++){
                    for(int j = 0; j < this->column; j++){
                        result.matrix[i][j] = this->matrix[i][j] + second.matrix[i][j];
                    }
                }
                return result;
            }
        }

        Matrix operator-(const Matrix& second){
            if(this->row != second.row || this->column != second.column){
                std::cout << "Matrices are not compatible for subtraction" << std::endl;
                return *this;
            }
            else{
                Matrix<T> result(this->row,this->column);
                for(int i = 0; i < this->row; i++){
                    for(int j = 0; j < this->column; j++){
                        result.matrix[i][j] = this->matrix[i][j] - second.matrix[i][j];
                    }
                }
                return result;
            }
        }

        void neg(){
            for(int i = 0; i < this->row; i++){
                for(int j = 0; j < this->column; j++){
                    this->matrix[i][j] = -this->matrix[i][j];
                }
            }
        }

        Matrix operator*(const Matrix& second){

            if(this->column != second.row){
                std::cout << "Matrices are not compatible for multiplication" << std::endl;
                return *this;
            }
            else{
                Matrix<T> result(this->row,second.column);
                for(int i = 0; i < this->row; i++){
                    for(int j = 0; j < second.column; j++){
                        for(int k = 0; k < this->column; k++){
                            result.matrix[i][j] += this->matrix[i][k] * second.matrix[k][j];
                        }
                    }
                }
                return result;
            }
        }
        
        T dot(Matrix& second){
            if(this->row != second.row || this->column != second.column){
                std::cout << "Matrices are not compatible for dot product" << std::endl;
                return 0;
            }
            else{
                T result = 0;
                for(int i = 0; i < this->row; i++){
                    for(int j = 0; j < this->column; j++){
                        result += this->matrix[i][j] * second.matrix[i][j];
                    }
                }
                return result;
            }
        }

        double magnitude(){ // calculate the magnitude of the matrix.
            T result = 0;
            for(int i = 0; i < this->row; i++){
                for(int j = 0; j < this->column; j++){
                    result += this->matrix[i][j] * this->matrix[i][j];
                }
            }
            return sqrt(result);
        }

        const std::string print() const{
            std::string result = "";
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[i].size(); j++){
                    if(matrix[i][j] < 0){
                        result += "-";
                        result += std::to_string(-matrix[i][j]);
                    }
                    else{
                        result += " ";
                        result += std::to_string(matrix[i][j]);
                    }
                    result += " ";
                }
                result += "\n";
            }
            return result;
        }

        friend std::ostream &operator<<(std::ostream &os, Matrix<T> const &m){ 
            os << m.print();
            return os;
        }
        
    private:
        int row;
        int column;
        std::vector<std::vector<T>> matrix;
};