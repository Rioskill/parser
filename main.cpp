#include <iostream>
#include "Parser.h"
#include "Fraction.h"

int main(int argc, char *argv[])
{
    Parser parser;

    std::cout << "result: " << parser.parse("3/2 + 7/9 + (8 + 6*7/2)");

    return 0;
}
