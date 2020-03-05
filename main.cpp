#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Operator.h"
#include "Parser.h"
#include "Stack.h"
#include "Fraction.h"
#include "Sieve_of_eratosthenes.h"

int main(int argc, char *argv[])
{
    Parser parser;

    std::cout << "result: " << parser.parse("17 / 8 * 2");
    return 0;
}
