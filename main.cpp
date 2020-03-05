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
    Fraction a;

    std::cin >> a;
    a.reduce();
    std::cout << a;

    return 0;
}
