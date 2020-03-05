//
// Created by nikstarling on 2/16/20.
//

#include "Operator.h"

Operator::Operator(int priority)
{
    this->priority = priority;
}

Operator::Operator()
{
    this->priority = 0;
}

Operator::Operator(Fraction (*func)(Fraction, Fraction), int priority)
{
    this->func = func;
    this->priority = priority;
}

Fraction Operator::execute(Fraction a, Fraction b)
{
    return this->func(a, b);
}

Fraction Operator::operator()(Fraction a, Fraction b)
{
    return this->func(a, b);
}

int Operator::get_priority()
{
    return this->priority;
}
