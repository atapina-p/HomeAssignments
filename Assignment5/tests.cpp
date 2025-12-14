/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 5
*/

#include "MatrixClass.h"
#include <gtest/gtest.h>
#include <vector>

TEST(IntMatrixTest, ConstructorAndAccess) {
    MatrixClass<int> m(2, 3);
    EXPECT_EQ(m.getRows(), 2);
    EXPECT_EQ(m.getCols(), 3);
    
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(0, 2) = 3;
    m(1, 0) = 4;
    m(1, 1) = 5;
    m(1, 2) = 6;
    
    EXPECT_EQ(m(0, 0), 1);
    EXPECT_EQ(m(1, 2), 6);
}

TEST(IntMatrixTest, ScalarMultiplication) {
    MatrixClass<int> m(2, 2);
    m(0, 0) = 1; m(0, 1) = 2;
    m(1, 0) = 3; m(1, 1) = 4;
    
    MatrixClass<int> result = m * 3;
    EXPECT_EQ(result(0, 0), 3);
    EXPECT_EQ(result(0, 1), 6);
    EXPECT_EQ(result(1, 0), 9);
    EXPECT_EQ(result(1, 1), 12);
    
    m *= 2;
    EXPECT_EQ(m(0, 0), 2);
    EXPECT_EQ(m(1, 1), 8);
}

TEST(IntMatrixTest, MatrixAddition) {
    MatrixClass<int> A(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;
    
    MatrixClass<int> B(2, 2);
    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;
    
    MatrixClass<int> C = A + B;
    EXPECT_EQ(C(0, 0), 6);
    EXPECT_EQ(C(0, 1), 8);
    EXPECT_EQ(C(1, 0), 10);
    EXPECT_EQ(C(1, 1), 12);
    
    A += B;
    EXPECT_EQ(A(0, 0), 6);
    EXPECT_EQ(A(1, 1), 12);
}

TEST(IntMatrixTest, MatrixMultiplication) {
    MatrixClass<int> A(2, 3);
    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
    
    MatrixClass<int> B(3, 2);
    B(0, 0) = 7;  B(0, 1) = 8;
    B(1, 0) = 9;  B(1, 1) = 10;
    B(2, 0) = 11; B(2, 1) = 12;
    
    MatrixClass<int> C = A * B;
    EXPECT_EQ(C.getRows(), 2);
    EXPECT_EQ(C.getCols(), 2);
    EXPECT_EQ(C(0, 0), 58);   
    EXPECT_EQ(C(0, 1), 64);   
    EXPECT_EQ(C(1, 0), 139);  
    EXPECT_EQ(C(1, 1), 154);  
}

TEST(IntMatrixTest, Transpose) {
    MatrixClass<int> m(2, 3);
    m(0, 0) = 1; m(0, 1) = 2; m(0, 2) = 3;
    m(1, 0) = 4; m(1, 1) = 5; m(1, 2) = 6;
    
    MatrixClass<int> t = m.transpose();
    EXPECT_EQ(t.getRows(), 3);
    EXPECT_EQ(t.getCols(), 2);
    EXPECT_EQ(t(0, 0), 1);
    EXPECT_EQ(t(0, 1), 4);
    EXPECT_EQ(t(1, 0), 2);
    EXPECT_EQ(t(2, 1), 6);
}

TEST(IntMatrixTest, InvalidOperations) {
    MatrixClass<int> A(2, 3);
    MatrixClass<int> B(3, 2);
    
    // Size mismatch for addition
    EXPECT_THROW(A + B, std::invalid_argument);
    
    // Size mismatch for multiplication
    MatrixClass<int> C(4, 4);
    EXPECT_THROW(A * C, std::invalid_argument);
    
    // Going beyond borders
    EXPECT_THROW(A(5, 5), std::out_of_range);
    EXPECT_THROW(A(-1, 0), std::out_of_range);
    
    // Incorrect dimensions when creating
    EXPECT_THROW(MatrixClass<int>(0, 5), std::invalid_argument);
    EXPECT_THROW(MatrixClass<int>(1, 0), std::invalid_argument);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}