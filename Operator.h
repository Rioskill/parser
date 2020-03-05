#ifndef PARSER_OPERATOR_H
#define PARSER_OPERATOR_H

#include "Fraction.h"

class Operator
{
private:
    Fraction (*func)(Fraction a, Fraction b);
    int priority;
public:
    Operator(Fraction (*func)(Fraction, Fraction), int priority);
    Operator();
    Operator(int priority);

    Fraction execute(Fraction a, Fraction b);

    int get_priority();

    Fraction operator() (Fraction a, Fraction b);
};

#endif //PARSER_OPERATOR_H
