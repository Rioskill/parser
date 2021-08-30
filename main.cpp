#include <iostream>
#include "Parser.h"
#include "Fraction.h"

int main(int argc, char *argv[])
{
    Parser parser(false);
    bool running = true;

    while(running)
    {
        std::string in;
        std::getline(std::cin, in);
        if(in == "exit" || in == "quit")
            running = false;
        else
            std::cout << "result: " << parser.parse(in) << std::endl;
    }

    return 0;
}
