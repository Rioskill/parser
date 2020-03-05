#include <iostream>
#include "Parser.h"
#include "Fraction.h"

int main(int argc, char *argv[])
{
    Parser parser;

    std::cout << "result: " << parser.parse("(2 / 3 + 4 / 5) * 5 / 2");
    return 0;
}
