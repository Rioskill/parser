//
// Created by nikstarling on 3/4/20.
//

#include "Fraction.h"

Sieve_of_eratosthenes Fraction::prime_numbers(100);

void Fraction::reduce()
{

    for(int i = 0; i < prime_numbers.get_size(); ++i)
    {
        int num = prime_numbers[i];
        if((this->numerator % num == 0) && (this->denominator % num == 0))
        {
            this->numerator /= num;
            this->denominator /= num;
            i = -1;
        }
    }
}

Fraction::operator int() {
    if (numerator * denominator > 0)return numerator / denominator;
    else return numerator / denominator - 1;
}

Fraction::operator double(){
    return (double)numerator / denominator;
}

bool operator<(double a, Fraction b) {
    return a < (double(b.numerator) / double(b.denominator));
}

Fraction operator*(int a, Fraction b) {
    Fraction res;
    res.numerator = b.numerator * a;
    res.denominator = b.denominator;

    res.reduce();

    return res;
}

std::istream& operator>>(std::istream &in, Fraction &a) {
    char k;
    in >> a.numerator >> k >> a.denominator;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Fraction &a) {
    if(a.denominator == 1)
        out << a.numerator;
    else
        out << a.numerator << "/" << a.denominator;
    return out;
}

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int number)
{
    this->numerator = number;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int znam = 1) {
    this->numerator = numerator;
    this->denominator = znam;
}

bool Fraction::operator<(Fraction b) {
    if (numerator * denominator < 0 && b.numerator * denominator > 0)return true;
    if (numerator * denominator > 0 && b.numerator * denominator < 0)return false;

    numerator *= b.denominator;
    b.numerator *= denominator;

    bool k = false;
    if (numerator < b.numerator)k = true;
    numerator /= b.denominator;
    b.numerator /= denominator;

    return k;
}
bool Fraction::operator>(Fraction b) {
    if (numerator * denominator < 0 && b.numerator * denominator > 0)return false;
    if (numerator * denominator > 0 && b.numerator * denominator < 0)return true;

    numerator *= b.denominator;
    b.numerator *= denominator;

    bool k = false;
    if (numerator > b.numerator)k = true;
    numerator /= b.denominator;
    b.numerator /= denominator;

    return k;
}

bool Fraction::operator==(Fraction b) {
    numerator *= b.denominator;
    b.numerator *= denominator;

    bool k = false;
    if (numerator == b.numerator)k = true;
    numerator /= b.denominator;
    b.numerator /= denominator;

    return k;
}

Fraction Fraction::operator-() {
    Fraction c;

    c.numerator = -numerator;
    c.denominator = denominator;

    return c;
}

Fraction Fraction::operator+(Fraction b) {
    Fraction c;

    numerator *= b.denominator;
    b.numerator *= denominator;
    c.denominator = denominator * b.denominator;
    c.numerator = numerator + b.numerator;

    c.reduce();

    return c;
}

Fraction Fraction::operator-(Fraction b) {
    Fraction c;

    numerator *= b.denominator;
    b.numerator *= denominator;
    c.denominator = denominator * b.denominator;
    c.numerator = numerator - b.numerator;

    c.reduce();

    return c;
}

Fraction Fraction::operator*(Fraction b) {
    Fraction c;

    c.numerator = numerator * b.numerator;
    c.denominator = denominator * b.denominator;

    c.reduce();

    return c;
}

Fraction Fraction::operator/(Fraction b) {
    Fraction c;

    c.numerator = numerator * b.denominator;
    c.denominator = denominator * b.numerator;

    c.reduce();

    return c;
}

Fraction Fraction::operator%(Fraction b) {
    Fraction c;

    c.numerator = (numerator * b.denominator) % (b.numerator * denominator);
    c.denominator = denominator * b.denominator;

    c.reduce();

    return c;
}
