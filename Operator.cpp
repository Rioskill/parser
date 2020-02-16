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

Operator::Operator(double (*func)(double, double), int priority)
{
    this->func = func;
    this->priority = priority;
}

double Operator::execute(double a, double b)
{
    return this->func(a, b);
}

double Operator::operator()(double a, double b)
{
    return this->func(a, b);
}

int Operator::get_priority()
{
    return this->priority;
}
