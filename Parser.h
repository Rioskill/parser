#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "Operator.h"
#include "Fraction.h"

class Parser {
private:
    std::map<std::string, Operator> operators;
    bool show_debug_information;
    std::vector<std::string> get_all_operator_keys();
public:
    Parser();
    Parser(bool show_debug_information);

    void print_debug_information(std::vector<Fraction> numbers, std::vector<std::string> operators);

    void count(std::vector<Fraction>&, std::vector<std::string>&, int min_priority = 10);
    Fraction parse(std::string);
};


#endif //PARSER_PARSER_H
