#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Operator.h"
#include "Parser.h"
#include "Stack.h"

int main(int argc, char *argv[])
{
    Parser parser(false);

    std::string input;

    getline(std::cin, input);

    std::cout << "result: " << parser.parse(input) << std::endl;

    return 0;
}
