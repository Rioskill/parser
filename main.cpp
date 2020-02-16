#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Operator.h"
#include "Parser.h"
#include "Stack.h"

int main()
{
    Parser parser;

    std::string input;

    while(1)
    {

        getline(std::cin, input);

        std::cout << "result: " << parser.parse(input) << std::endl;
        std::cout << "--------------------" << std::endl;

    }

    return 0;
}
