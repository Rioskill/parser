//
// Created by nikstarling on 2/16/20.
//

#ifndef PARSER_STACK_H
#define PARSER_STACK_H


template <class T>
class Stack {
private:
    int cursor;
    int size;
    T *data;
public:
    Stack(int size);
    Stack(int size, T base_value);
    ~Stack();
    Stack(const Stack& stack );

    void push(T value);
    T last();
    T pop();
    int get_size();
    int get_cursor();

    T operator[](int i);
};


template <class T>
Stack<T>::Stack(const Stack& stack)
{
    this->cursor = stack.cursor;
    this->size = stack.size;
    this->data = new T[this->size];
    for(int i = 0; i < this->size; ++i)
        this->data[i] = stack.data[i];
}


template <class T>
int Stack<T>::get_cursor()
{
    return this->cursor;
}

template <class T>
T Stack<T>::operator[](int i)
{
    return this->data[i];
}

template <class T>
int Stack<T>::get_size()
{
    return this->size;
}

template <class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    this->data = new T[size];
    this->cursor = 0;
}

template <class T>
Stack<T>::Stack(int size, T base_value)
{
    this->size = size;
    this->data = new T[size];
    this->cursor = 0;
    for(int i = 0; i < size; ++i)
        this->data = base_value;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] this->data;
}

template <class T>
void Stack<T>::push(T value)
{
    if(this->cursor < this->size)
        this->data[this->cursor++] = value;
}

template <class T>
T Stack<T>::last()
{
    return this->data[this->cursor - 1];
}

template <class T>
T Stack<T>::pop()
{
    return this->data[--this->cursor];
}

template <class T>
void print(Stack<T> stack)
{
    for(int i = 0; i < stack.get_cursor(); ++i)
        std::cout << stack[i] << " ";
    std::cout << std::endl;
}

#endif //PARSER_STACK_H
