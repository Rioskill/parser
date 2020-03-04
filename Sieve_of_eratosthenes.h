//
// Created by nikstarling on 3/4/20.
//

#ifndef PARSER_SIEVE_OF_ERATOSTHENES_H
#define PARSER_SIEVE_OF_ERATOSTHENES_H


#include "LinkedList.h"

class Sieve_of_eratosthenes {

    LinkedList<int> prime_numbers;
public:
    Sieve_of_eratosthenes(unsigned int right_border);
};


#endif //PARSER_SIEVE_OF_ERATOSTHENES_H
