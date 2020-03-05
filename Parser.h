#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "Operator.h"
#include "Stack.h"
#include "Fraction.h"

class Parser {
private:
    std::map<std::string, Operator> operators;
    bool show_debug_information;
public:
    Parser();
    Parser(bool show_debug_information);

    void print_debug_information(Stack<Fraction> numbers, Stack<std::string> operators);

    void count(Stack<Fraction>&, Stack<std::string>&);
    Fraction parse(std::string);
};


#endif //PARSER_PARSER_H
