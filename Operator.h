#ifndef PARSER_OPERATOR_H
#define PARSER_OPERATOR_H


class Operator
{
private:
    double (*func)(double a, double b);
    int priority;
public:
    Operator(double (*func)(double, double), int priority);
    Operator();
    Operator(int priority);

    double execute(double a, double b);

    int get_priority();

    double operator() (double a, double b);
};

#endif //PARSER_OPERATOR_H
