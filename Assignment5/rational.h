/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 5
*/

#ifndef RATIONAL
#define RATIONAL

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cmath>


class Rational
{
private:
    int numerator;
    int denominator;
    // Reduction to normal form (invariant: denominator > 0)
    void normalize();


public:
    // Constructor
    Rational();
    Rational(int num);
    Rational(int num, int den);
    ~Rational(); // Destructor

    // Getters
    int getNumerator() const;
    int getDenominator() const;


    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    Rational operator-() const;

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    double toDouble() const;

    // Checking the invariant
    bool isNormalized() const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

};

#endif // RATIONAL_H