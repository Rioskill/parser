//
// Created by nikstarling on 2/16/20.
//

#include "Parser.h"

std::string add_extra_spaces(std::string input)
{
    std::string res;
    for(auto symbol: input)
    {
        if(symbol == '(' || symbol == ')')
        {
            res = res + ' ' + symbol + ' ';
        } else{
            res += symbol;
        }
    }
    return res;
}

std::vector<std::string> split(std::string S, char splitter = ' ')
{
    std::vector<std::string> result;
    std::string word;
    for(auto symbol: S)
    {
        if(symbol == splitter)
        {
            if(word != "")
            {
                result.push_back(word);
                word = "";
            }
        }
        else
        {
            word += symbol;
        }
    }
    if(word != "")
        result.push_back(word);
    return result;
}

Parser::Parser(){
    this->operators = {
            {"+", Operator([](double a, double b){return a + b;}, 3)},
            {"-", Operator([](double a, double b){return a - b;}, 3)},
            {"*", Operator([](double a, double b){return a * b;}, 2)},
            {"/", Operator([](double a, double b){return a / b;}, 2)},
            {"(", Operator(-100)},
            {")", Operator(100)}
    };
}

void Parser::print_debug_information(Stack<double> numbers, Stack<std::string> operators)
{
    std::cout << "numbers: ";
    print(numbers);
    std::cout << "operators: ";
    print(operators);
    std::cout << "--------------------" << std::endl;
}

void Parser::count(Stack<double> &numbers, Stack<std::string> &ops)
{
    while(ops.get_cursor() > 0 && ops.last()!= "(")
    {
        print_debug_information(numbers, ops);

        double first = numbers.pop();
        double second = numbers.pop();
        numbers.push(this->operators[ops.pop()].execute(first, second));
    }
}

double Parser::parse(std::string input)
{
    Stack<double> numbers(100);
    Stack<std::string> operators(100);

    std::vector<std::string> splitted = split(add_extra_spaces(input));

    for(auto word: splitted)
    {
        if(word == ")")
        {
            count(numbers, operators);
            operators.pop();
        }
        else if(this->operators.find(word) != this->operators.end())
        {
            auto op = this->operators[word];
            auto last = this->operators[operators.last()];
            if(operators.get_cursor() > 0 && op.get_priority() > last.get_priority() && operators.last() != "(")
                count(numbers, operators);
            operators.push(word);
        } else{
            numbers.push(std::stod(word));
        }

    }

    count(numbers, operators);

    double res = numbers.pop();

    return res;

}

