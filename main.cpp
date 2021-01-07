#include <iostream>
#include "Parser.h"
#include "Fraction.h"

int main(int argc, char *argv[])
{
    Parser parser(false);
    std::string in;
    std::getline(std::cin, in);
    std::cout << "result: " << parser.parse(in) << std::endl;

    return 0;
}
