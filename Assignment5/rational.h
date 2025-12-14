#ifndef RATIONAL
#define RATIONAL

#include <iostream>
#include <numeric>  
#include <stdexcept>
#include <cmath>


class Rational {
private:
    int numerator;
    int denominator;
    
    // Reduction to normal form (invariant: denominator > 0)
    void normalize() {
        if (denominator == 0) {
            throw std::runtime_error("Denominator cannot be zero");
        }
        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        
        int gcd = std::gcd(std::abs(numerator), denominator);
        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
    }
    
public:
    // Constructor
    Rational() : numerator(0), denominator(1) {}
    
    Rational(int num) : numerator(num), denominator(1) {}
    
    Rational(int num, int den) : numerator(num), denominator(den) {
        normalize();
    }
    ~Rational(){}; // Destructor
    
    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    

    Rational operator+(const Rational& other) const {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }
    
    Rational operator-(const Rational& other) const {
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }
    
    Rational operator*(const Rational& other) const {
        return Rational(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }
    
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Rational(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }
    
    Rational operator-() const {
        return Rational(-numerator, denominator);
    }
    
    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }
    
    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }
    
    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }
    
    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }
    
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }
    
    // Checking the invariant
    bool isNormalized() const {
        if (denominator <= 0) return false;
        if (std::gcd(std::abs(numerator), denominator) != 1) return false;
        return true;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        if (r.denominator == 1) {
            os << r.numerator;
        } else {
            os << r.numerator << "/" << r.denominator;
        }
        return os;
    }
    
};

#endif // RATIONAL_H