/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 5
*/


#include "rational.h"
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cmath>

Rational::Rational(): numerator(0), denominator(1) {}

Rational::Rational(int num): numerator(num), denominator(1) {}

Rational::Rational(int num, int den) : numerator(num), denominator(den)
{
    normalize();
}
Rational::~Rational() {} // Destructor

// Getters
int Rational::getNumerator() const
{
    return numerator;
}
int Rational::getDenominator() const
{
    return denominator;
}


Rational Rational::operator+(const Rational& other) const
{
    return Rational(
               numerator * other.denominator + other.numerator * denominator,
               denominator * other.denominator
           );
}

Rational Rational::operator-(const Rational& other) const
{
    return Rational(
               numerator * other.denominator - other.numerator * denominator,
               denominator * other.denominator
           );
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational(
               numerator * other.numerator,
               denominator * other.denominator
           );
}

Rational Rational::operator/(const Rational& other) const
{
    if (other.numerator == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    return Rational(
               numerator * other.denominator,
               denominator * other.numerator
           );
}

Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const
{
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

double Rational::toDouble() const
{
    return static_cast<double>(numerator) / denominator;
}

// Checking the invariant
bool Rational::isNormalized() const
{
    if (denominator <= 0) return false;
    if (std::gcd(std::abs(numerator), denominator) != 1) return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    if (r.denominator == 1)
    {
        os << r.numerator;
    }
    else
    {
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

void Rational::normalize()
{
    if (denominator == 0)
    {
        throw std::runtime_error("Denominator cannot be zero");
    }

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int gcd = std::gcd(std::abs(numerator), denominator);
    if (gcd > 1)
    {
        numerator /= gcd;
        denominator /= gcd;
    }
}