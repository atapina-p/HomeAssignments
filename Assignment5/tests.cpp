#include "MatrixClass.h"


int main() {
    try {
        MatrixClass<int> A(2, 3);
        A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
        A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
        
        MatrixClass<int> B(2, 3);
        B(0, 0) = 2; B(0, 1) = 3; B(0, 2) = 4;
        B(1, 0) = 5; B(1, 1) = 6; B(1, 2) = 7;
        

        // Умножение на скаляр
        MatrixClass<int> scaled = A * 2;
        std::cout << scaled << std::endl;

        // Сложение матриц
        MatrixClass<int> sum = A + B;
        std::cout << sum << std::endl;

        MatrixClass<int> C(3, 2);
        C(0, 0) = 1; C(0, 1) = 2;
        C(1, 0) = 3; C(1, 1) = 4;
        C(2, 0) = 5; C(2, 1) = 6;

        MatrixClass<int> product = A * C;
        std::cout << product << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}