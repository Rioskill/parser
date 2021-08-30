#include "Parser.h"

std::string add_extra_spaces(std::string input, std::vector<std::string> stop_symbols)
{
    std::string res;
    for(int i = 0; i < input.length(); ++i)
    {
        std::string symbol = input.substr(i, 1);
        bool found = false;
        for(auto stop_symbol: stop_symbols)
        {
            if(symbol == stop_symbol)
            {
                auto str = ' ' + symbol + ' ';
                res += str;
                found = true;
            }
        }
        if(!found)
            res += symbol;
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
            {"+", Operator([](Fraction a, Fraction b){return a + b;}, 3)},
            {"-", Operator([](Fraction a, Fraction b){return a - b;}, 3)},
            {"*", Operator([](Fraction a, Fraction b){return a * b;}, 2)},
            {"/", Operator([](Fraction a, Fraction b){return a / b;}, 2)},
            {"(", Operator(-100)},
            {")", Operator(100)}
    };
    this->show_debug_information = false;
}

std::vector<std::string> Parser::get_all_operator_keys()
{
    std::vector<std::string> res;
    for(auto it = this->operators.begin(); it != this->operators.end(); ++it)
    {
        res.push_back(it->first);
    }
    return res;
}

Parser::Parser(bool show_debug_information) : Parser()
{
    this->show_debug_information = show_debug_information;
}

template <typename T>
void print(std::vector<T> vector)
{
    for(auto &i : vector)
        std::cout << i << ' ';
    std::cout << std::endl;
}

void Parser::print_debug_information(std::vector<Fraction> numbers, std::vector<std::string> operators)
{
    if(!this->show_debug_information)
        return;
    std::cout << "numbers: ";
    print(numbers);
    std::cout << "operators: ";
    print(operators);
}

// TODO: rewrite this to use Stack instead of std::vector
void Parser::count(std::vector<Fraction> &numbers, std::vector<std::string> &ops, int max_priority)
{
    if(this->show_debug_information)
        std::cout << std::endl << "start of count with priority: " << max_priority << std::endl << std::endl;
    while(!ops.empty() && ops.back() != "(")
    {
        if(this->show_debug_information)
        {
            print_debug_information(numbers, ops);
            std::cout << "----------------" << std::endl;
        }
        if(this->operators[ops.back()].get_priority() > max_priority)
            break;


        Fraction a = numbers.back();
        numbers.pop_back();
        Fraction b = numbers.back();
        numbers.pop_back();

        Operator op = this->operators[ops.back()];
        ops.pop_back();
        numbers.push_back(op.execute(b, a));
    }
    if(this->show_debug_information)
    {
        print_debug_information(numbers, ops);
        std::cout << "----------------" << std::endl;
        std::cout << "end of count" << std::endl;
    }
}

Fraction Parser::parse(std::string input)
{
    std::vector<Fraction> numbers;
    std::vector<std::string> ops;

    std::vector<std::string> splitted = split(add_extra_spaces(input, this->get_all_operator_keys()));
    bool is_operator = true;

    for(auto &word: splitted)
    {
        if(word == ")")
        {
            count(numbers, ops);
            ops.pop_back();
        }
        else if (word == "-" && is_operator)
        {
            ops.push_back("unar-");
            numbers.push_back(-1);
        }
        else if (this->operators.find(word) != this->operators.end())  // if operator exists
        {
            auto op = this->operators[word];
            while(!ops.empty() && op.get_priority() >= this->operators[ops.back()].get_priority() && ops.back() != "(")
                count(numbers, ops, this->operators[ops.back()].get_priority());
            ops.push_back(word);
            is_operator = true;
        } else {
            numbers.push_back(std::stod(word));
            is_operator = false;
        }

    }

    count(numbers, ops);

    Fraction res = numbers.back();

    return res;

}
