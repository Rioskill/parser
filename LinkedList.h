//
// Created by nikstarling on 3/4/20.
//

#ifndef PARSER_LINKEDLIST_H
#define PARSER_LINKEDLIST_H

#include <iostream>

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head, *tail, *current;
    unsigned int size;

public:
    void create_node(T data);
    void delete_node(int id);

    unsigned int get_size(){return this->size;}

    LinkedList();
    ~LinkedList();

    template <class U>
    friend std::ostream& operator<<(std::ostream &out, LinkedList<U> &a);
};

template <class T>
void LinkedList<T>::delete_node(int id)
{
    this->current =  this->head;

    Node<T> *target;

    if(id == 0)
    {
        target = this->head;
        this->head = this->head->next;
    } else {
        for (int i = 0; i < id - 1; ++i) {
            this->current = this->current->next;
        }
        target = this->current->next;
        if (id != this->size - 1)
        {
            this->current->next = target->next;
        } else {
            this->current->next = NULL;
        }

    }
    delete target;
    this->size--;
}

template <class U>
std::ostream& operator<<(std::ostream &out, LinkedList<U> &a)
{
    a.current = a.head;
    while(a.current != NULL)
    {
        out << a.current->data << " ";
        a.current = a.current->next;
    }
    return out;
}

template <class T>
LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
    this->current = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *previous = head;
    while(this->current != NULL)
    {
        previous = this->current;
        this->current = this->current->next;
        delete previous;
    }
}

template <class T>
void LinkedList<T>::create_node(T data)
{
    Node<T> *node = new Node<T>;

    node->data = data;
    node->next = NULL;

    if(this->head == NULL)
    {
        this->head = node;
        this->tail = node;
        node = NULL;
        this->current = this->head;
    } else {
        this->tail->next = node;
        this->tail = node;
    }

    this->size++;
}


#endif //PARSER_LINKEDLIST_H
