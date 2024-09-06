#ifndef STACK_H
#define STACK_H

#include <iostream>

template<typename T>
class Stack {
private:
    T* elements;
    int _size;
    int _last;

public:
    Stack() : elements(new T[1]), _size(1), _last(-1) {}

    Stack(const int& size) : elements(new T[size]), _size(size), _last(-1) {}

    Stack(const Stack& other);

    ~Stack();

    bool empty() const { return _last < 0; }

    int length() const { return _last + 1; }

    void push(const T&);

    T& pop();
    
    T& top() const;

    T& operator[](const int&);
};

#include "stack.cpp"

#endif