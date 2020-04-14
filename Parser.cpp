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

void Parser::print_debug_information(Stack<Fraction> numbers, Stack<std::string> operators)
{
    std::cout << "numbers: ";
    print(numbers);
    std::cout << "operators: ";
    print(operators);
}

void Parser::count(Stack<Fraction> &numbers, Stack<std::string> &ops)
{
    Stack<Fraction> extra_numbers(50);
    Stack<std::string> extra_ops(50);
    int current_priority;

    while(( ops.get_size() > 0 || extra_ops.get_size() > 0 ))
    {
        if(this->show_debug_information)
        {
            std::cout << "normal:" << std::endl;
            print_debug_information(numbers, ops);
            std::cout << "-------" << std::endl;
            std::cout << "extra:" << std::endl;
            print_debug_information(extra_numbers, extra_ops);
            std::cout << "-----------------------------------" << std::endl;
        }

        if(ops.last() == "(")
        {
            Fraction first = extra_numbers.pop();
            Fraction second = extra_numbers.pop();
            extra_numbers.push(this->operators[extra_ops.pop()].execute(first, second));
            break;
        }

        if(extra_ops.get_size() == 0){
            if(extra_numbers.get_size() == 1)
                numbers.push(extra_numbers.pop());
            extra_ops.push(ops.pop());
            extra_numbers.push(numbers.pop());
            extra_numbers.push(numbers.pop());
            current_priority = this->operators[extra_ops.last()].get_priority();
        }
        else if(ops.get_size() > 0 && this->operators[ops.last()].get_priority() == current_priority)
        {
            extra_ops.push(ops.pop());
            extra_numbers.push(numbers.pop());
        }
        else {
            //print_debug_information(extra_numbers, extra_ops);

            Fraction first = extra_numbers.pop();
            Fraction second = extra_numbers.pop();
            extra_numbers.push(this->operators[extra_ops.pop()].execute(first, second));
        }
    }

    if(this->show_debug_information)
    {
        std::cout << "normal:" << std::endl;
        print_debug_information(numbers, ops);
        std::cout << "extra:" << std::endl;
        print_debug_information(extra_numbers, extra_ops);
        std::cout << "///////////////////////////////" << std::endl;
    }

    numbers.push(extra_numbers.pop());

    if(this->show_debug_information) {
        std::cout << "normal:" << std::endl;
        print_debug_information(numbers, ops);
        std::cout << "extra:" << std::endl;
        print_debug_information(extra_numbers, extra_ops);
        std::cout << "===============================" << std::endl;
    }
}

Fraction Parser::parse(std::string input)
{
    Stack<Fraction> numbers(100);
    Stack<std::string> ops(100);

    std::vector<std::string> splitted = split(add_extra_spaces(input, this->get_all_operator_keys()));


    for(auto word: splitted)
    {
        if(word == ")")
        {
            count(numbers, ops);
            ops.pop();
        }
        else if(this->operators.find(word) != this->operators.end())
        {
            auto op = this->operators[word];
            auto last = this->operators[ops.last()];
            if(ops.get_size() > 0 && op.get_priority() > last.get_priority() && ops.last() != "(")
                count(numbers, ops);
            ops.push(word);
        } else{
            numbers.push(std::stoi(word));
        }

    }

    count(numbers, ops);

    Fraction res = numbers.pop();

    return res;

}

