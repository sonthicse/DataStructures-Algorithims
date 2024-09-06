#include "stack.h"
#include <iostream>

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
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        // Clear current stack
        while (!empty()) {
            pop();
        }
        
        // Copy elements from other stack
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
    T result = head->data;
    Node* temp = head;
    head = head->next;
    _size--;
    delete temp;
    return result;
}

template<typename T>
T& Stack<T>::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}