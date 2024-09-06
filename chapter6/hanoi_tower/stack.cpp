#include "stack.h"
#include <stdexcept>

template<typename T>
Stack<T>::Stack(const Stack& other) : head(nullptr), _size(0) {
    for (Node* current = other.head; current != nullptr; current = current->next) {
        push(current->data);
    }
}

template<typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        while (!empty()) {
            pop();
        }
        for (Node* current = other.head; current != nullptr; current = current->next) {
            push(current->data);
        }
    }
    return *this;
}

template<typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    _size++;
}

template<typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = head;
    T result = head->data;
    head = head->next;
    _size--;
    delete temp;
    return result;
}

template<typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return head->data;
}

// Explicit instantiation for common types
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;