#include "../include/Matrix.hpp"

int main(){
    // Create two 3x3 matrices
    Matrix<int> m1{3, 3, {{2,-3,1},{2,0,-1},{1,4,5}}};
    Matrix<int> m2{3, 3, {{2,2,2},{2,2,2},{2,2,2}}};
    Matrix<int> m3{2,2,{{1,2},{3,4}}};

    std::cout << "M1 is: " << std::endl << m1 << std::endl;
    std::cout << "M2 is: " << std::endl << m2 << std::endl;

    std::cout << "Trace of m1 : "<< m1.trace() << std::endl;
    
    std::cout << "Determinant of m1 : " << m1.determinant() << std::endl;

    std::cout << "Magnitude of m1 is : " << m1.magnitude() << std::endl;

    std::cout << "Addition of m1 and m2 is: \n" << m1 + m2 << std::endl;

    std::cout << "Subtraction of m1 and m2 is: \n" << m1 - m2 << std::endl;

    std::cout << "Multiplication of m1 and m2 is: \n" << m1 * m2 << std::endl;

    std::cout << "Dot product of m1 and m2 is: " << m1.dot(m2) << std::endl;

    std::cout << "M3 is: " << std::endl << m3 << std::endl;
    
    std::cout << "Inverse of m3 is: \n";
    m3.inverse();
    std::cout << m3 << std::endl;

    std::cout << "Magnitute of m3 is: " << m3.magnitude() << std::endl;

    std::cout <<"Transpose of m3 is: \n";
    m3.transpose();
    std::cout << m3 << std::endl;

    std::cout << "M3 is: \n" << m3 << "M3 neg is: \n";
    m3.neg();
    std::cout << m3 << std::endl;
    
    return 0;
}