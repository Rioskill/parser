//
// Created by nikstarling on 3/4/20.
//

#include "Sieve_of_eratosthenes.h"

Sieve_of_eratosthenes::Sieve_of_eratosthenes(unsigned int right_border)
{
    LinkedList<int> prime_numbers;
    for(int i = 2; i < right_border; ++i)
    {
        prime_numbers.create_node(i);
    }

    for(prime_numbers.set_head(); prime_numbers.get_next() != NULL; prime_numbers.set_next())
    {
        Node<int> *temp;
        for(temp = prime_numbers.get_current(); temp->next != NULL; temp = temp->next)
        {
            if(temp->next->data % prime_numbers.get_current()->data == 0)
            {
                temp->delete_next();
                prime_numbers.shrink();
            }
        }
    }

    this->data = new int[prime_numbers.get_size()];

    prime_numbers.set_head();
    for(int i = 0; i < prime_numbers.get_size(); ++i)
    {
        this->data[i] = prime_numbers.get_current()->data;
        prime_numbers.set_next();
    }

    this->size = prime_numbers.get_size();

}

int Sieve_of_eratosthenes::operator[](int x)
{
    return this->data[x];
}

Sieve_of_eratosthenes::~Sieve_of_eratosthenes()
{
    delete[] data;
}