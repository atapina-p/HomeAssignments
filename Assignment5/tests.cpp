/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 5
*/

#include "MatrixClass.h"
#include "rational.h"
#include <gtest/gtest.h>
#include <vector>


// tests for int type

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

TEST(IntMatrixTest, Equality) {
    MatrixClass<int> A(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;
    
    MatrixClass<int> B(2, 2);
    B(0, 0) = 1; B(0, 1) = 2;
    B(1, 0) = 3; B(1, 1) = 4;
    
    MatrixClass<int> C(2, 2);
    C(0, 0) = 1; C(0, 1) = 2;
    C(1, 0) = 3; C(1, 1) = 5;
    
    EXPECT_TRUE(A == B);
    EXPECT_FALSE(A == C);
    EXPECT_TRUE(A != C);
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

// tests for double type

TEST(DoubleMatrixTest, BasicOperations) {
    MatrixClass<double> A(2, 2);
    A(0, 0) = 1.5; A(0, 1) = 2.5;
    A(1, 0) = 3.5; A(1, 1) = 4.5;
    
    MatrixClass<double> B(2, 2);
    B(0, 0) = 0.5; B(0, 1) = 1.5;
    B(1, 0) = 2.5; B(1, 1) = 3.5;
    
    MatrixClass<double> C = A + B;
    EXPECT_DOUBLE_EQ(C(0, 0), 2.0);
    EXPECT_DOUBLE_EQ(C(0, 1), 4.0);
    EXPECT_DOUBLE_EQ(C(1, 0), 6.0);
    EXPECT_DOUBLE_EQ(C(1, 1), 8.0);
    
    MatrixClass<double> D = A * 2.0;
    EXPECT_DOUBLE_EQ(D(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(D(1, 1), 9.0);
}

TEST(DoubleMatrixTest, MatrixMultiplicationPrecision) {
    MatrixClass<double> A(2, 2);
    A(0, 0) = 0.1; A(0, 1) = 0.2;
    A(1, 0) = 0.3; A(1, 1) = 0.4;
    
    MatrixClass<double> B(2, 2);
    B(0, 0) = 0.5; B(0, 1) = 0.6;
    B(1, 0) = 0.7; B(1, 1) = 0.8;
    
    MatrixClass<double> C = A * B;
    EXPECT_NEAR(C(0, 0), 0.19, 1e-10); 
    EXPECT_NEAR(C(0, 1), 0.22, 1e-10); 
    EXPECT_NEAR(C(1, 0), 0.43, 1e-10); 
    EXPECT_NEAR(C(1, 1), 0.50, 1e-10); 
}

TEST(DoubleMatrixTest, TransposeAndEquality) {
    MatrixClass<double> A(2, 3);
    A(0, 0) = 1.1; A(0, 1) = 2.2; A(0, 2) = 3.3;
    A(1, 0) = 4.4; A(1, 1) = 5.5; A(1, 2) = 6.6;
    
    MatrixClass<double> B = A.transpose();
    EXPECT_DOUBLE_EQ(B(0, 0), 1.1);
    EXPECT_DOUBLE_EQ(B(1, 0), 2.2);
    EXPECT_DOUBLE_EQ(B(2, 1), 6.6);

    MatrixClass<double> C = B.transpose();
    EXPECT_TRUE(A == C);
}

// tests for rational numbers class

TEST(RationalTest, ConstructorAndNormalization) {
    Rational r1(3, 4);
    EXPECT_EQ(r1.getNumerator(), 3);
    EXPECT_EQ(r1.getDenominator(), 4);
    EXPECT_TRUE(r1.isNormalized());
    
    Rational r2(6, 8);
    EXPECT_EQ(r2.getNumerator(), 3);
    EXPECT_EQ(r2.getDenominator(), 4);
    EXPECT_TRUE(r2.isNormalized());
    
    Rational r3(-2, 3);
    EXPECT_EQ(r3.getNumerator(), -2);
    EXPECT_EQ(r3.getDenominator(), 3);
    EXPECT_TRUE(r3.isNormalized());
    
    Rational r4(2, -3);
    EXPECT_EQ(r4.getNumerator(), -2);
    EXPECT_EQ(r4.getDenominator(), 3);
    EXPECT_TRUE(r4.isNormalized());
    
    Rational r5(0, 5);  // 0/5 = 0/1
    EXPECT_EQ(r5.getNumerator(), 0);
    EXPECT_EQ(r5.getDenominator(), 1);
    EXPECT_TRUE(r5.isNormalized());
    
    EXPECT_THROW(Rational(1, 0), std::runtime_error);
}

TEST(RationalTest, ArithmeticOperations) {
    Rational a(1, 2);
    Rational b(1, 3);
    
    Rational c = a + b;  
    EXPECT_EQ(c.getNumerator(), 5);
    EXPECT_EQ(c.getDenominator(), 6);
    EXPECT_TRUE(c.isNormalized());
    
    Rational d = a - b; 
    EXPECT_EQ(d.getNumerator(), 1);
    EXPECT_EQ(d.getDenominator(), 6);
    EXPECT_TRUE(d.isNormalized());
    
    Rational e = a * b;  
    EXPECT_EQ(e.getNumerator(), 1);
    EXPECT_EQ(e.getDenominator(), 6);
    EXPECT_TRUE(e.isNormalized());
    
    Rational f = a / b;  
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 2);
    EXPECT_TRUE(f.isNormalized());
    
    Rational zero(0);
    EXPECT_THROW(a / zero, std::runtime_error);
}

TEST(RationalTest, EqualityOperator) {
    Rational a(1, 2);
    Rational b(2, 4);
    Rational c(1, 3);
    
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a != c);
}

// tests for rational type

TEST(RationalMatrixTest, MatrixOperationsWithRational) {
    MatrixClass<Rational> A(2, 2);
    A(0, 0) = Rational(1, 2); A(0, 1) = Rational(1, 3);
    A(1, 0) = Rational(2, 3); A(1, 1) = Rational(3, 4);
    
    MatrixClass<Rational> B(2, 2);
    B(0, 0) = Rational(1, 4); B(0, 1) = Rational(1, 5);
    B(1, 0) = Rational(1, 6); B(1, 1) = Rational(1, 7);
    

    MatrixClass<Rational> C = A + B;
    EXPECT_EQ(C(0, 0), Rational(3, 4));  
    EXPECT_EQ(C(0, 1), Rational(8, 15)); 
    EXPECT_TRUE(C(0, 0).isNormalized());
    EXPECT_TRUE(C(0, 1).isNormalized());
    

    MatrixClass<Rational> D = A * Rational(2);
    EXPECT_EQ(D(0, 0), Rational(1, 1));  
    EXPECT_EQ(D(1, 1), Rational(3, 2));  
    

    MatrixClass<Rational> E(2, 1);
    E(0, 0) = Rational(1, 2);
    E(1, 0) = Rational(2, 3);
    
    MatrixClass<Rational> F = A * E;
    EXPECT_EQ(F.getRows(), 2);
    EXPECT_EQ(F.getCols(), 1);
    EXPECT_EQ(F(0, 0), Rational(17, 36));
    EXPECT_EQ(F(1, 0), Rational(5, 6));
    
    // Checking invariance
    for (int i = 0; i < F.getRows(); ++i) {
        for (int j = 0; j < F.getCols(); ++j) {
            EXPECT_TRUE(F(i, j).isNormalized());
        }
    }
}

TEST(RationalMatrixTest, TransposeAndEquality) {
    MatrixClass<Rational> A(2, 3);
    A(0, 0) = Rational(1, 2); A(0, 1) = Rational(1, 3); A(0, 2) = Rational(1, 4);
    A(1, 0) = Rational(2, 3); A(1, 1) = Rational(3, 4); A(1, 2) = Rational(4, 5);
    
    MatrixClass<Rational> B = A.transpose();
    EXPECT_EQ(B.getRows(), 3);
    EXPECT_EQ(B.getCols(), 2);
    EXPECT_EQ(B(0, 0), Rational(1, 2));
    EXPECT_EQ(B(1, 0), Rational(1, 3));
    EXPECT_EQ(B(2, 1), Rational(4, 5));
    
    // Checking invariance
    for (int i = 0; i < B.getRows(); ++i) {
        for (int j = 0; j < B.getCols(); ++j) {
            EXPECT_TRUE(B(i, j).isNormalized());
        }
    }
    
    MatrixClass<Rational> C = B.transpose();
    EXPECT_TRUE(A == C);
}

TEST(RationalMatrixTest, ComplexOperations) {
    // Test: (A + B) * C == A*C + B*C
    MatrixClass<Rational> A(2, 2);
    A(0, 0) = Rational(1, 2); A(0, 1) = Rational(1, 3);
    A(1, 0) = Rational(2, 3); A(1, 1) = Rational(3, 4);
    
    MatrixClass<Rational> B(2, 2);
    B(0, 0) = Rational(1, 4); B(0, 1) = Rational(1, 5);
    B(1, 0) = Rational(1, 6); B(1, 1) = Rational(1, 7);
    
    MatrixClass<Rational> C(2, 2);
    C(0, 0) = Rational(2, 1); C(0, 1) = Rational(1, 2);
    C(1, 0) = Rational(1, 3); C(1, 1) = Rational(3, 1);
    
    MatrixClass<Rational> left = (A + B) * C;
    MatrixClass<Rational> right = A * C + B * C;
    
    EXPECT_TRUE(left == right);
    
    // Checking invariance
    for (int i = 0; i < left.getRows(); ++i) {
        for (int j = 0; j < left.getCols(); ++j) {
            EXPECT_TRUE(left(i, j).isNormalized());
            EXPECT_TRUE(right(i, j).isNormalized());
        }
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}