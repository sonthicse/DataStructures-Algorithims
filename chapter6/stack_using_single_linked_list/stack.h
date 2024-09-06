#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<typename T>
class Stack {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int _size;

public:
    // Constructor
    Stack() : head(nullptr), _size(0) {}

    // Copy constructor
    Stack(const Stack& other);

    // Destructor
    ~Stack();

    // Copy assignment operator
    Stack& operator=(const Stack& other);

    // Check if the stack is empty
    bool empty() const { return _size == 0; }

    // Get the size of the stack
    int size() const { return _size; }

    // Push an element onto the stack
    void push(const T& value);

    // Pop an element from the stack
    T pop();

    // Access an element by index (for testing purposes only)
    T& operator[](int index) const;
};

#include "stack.cpp"

#endif