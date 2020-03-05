//
// Created by nikstarling on 3/4/20.
//

#ifndef PARSER_SIEVE_OF_ERATOSTHENES_H
#define PARSER_SIEVE_OF_ERATOSTHENES_H


#include "LinkedList.h"

class Sieve_of_eratosthenes {
private:
    int *data;
    unsigned int size;

public:
    Sieve_of_eratosthenes(unsigned int right_border = 100);

    ~Sieve_of_eratosthenes();

    //void generate(unsigned int right_border);
    unsigned int get_size(){return this->size;}

    int operator[](int x);
};


#endif //PARSER_SIEVE_OF_ERATOSTHENES_H
