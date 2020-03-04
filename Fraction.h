//
// Created by nikstarling on 3/4/20.
//

#ifndef PARSER_FRACTION_H
#define PARSER_FRACTION_H

#include <cmath>
#include <iostream>

#include "LinkedList.h"

//class Sieve_of_eratosthenes
//{
//
//};

class Fraction {
private:
    long long numerator;
    long long denominator;

    void reduce();

public:
    Fraction();
    Fraction(int number);
    Fraction(int numerator, int denominator);
    Fraction operator+(Fraction b);
    Fraction operator-(Fraction b);
    Fraction operator*(Fraction b);
    Fraction operator/(Fraction b);
    Fraction operator%(Fraction b);
    Fraction operator-();

    bool operator<(Fraction b);
    bool operator>(Fraction b);
    bool operator==(Fraction b);

    friend std::ostream& operator<<(std::ostream &out, Fraction &a);
    friend std::istream& operator>>(std::istream &in, Fraction &a);

    friend Fraction operator*(int a, Fraction b);

    friend bool operator<(double a, Fraction b);

    operator double();
    operator int();
};


#endif //PARSER_FRACTION_H
