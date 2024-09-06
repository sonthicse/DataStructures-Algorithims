#include "stack.h"
#include <cassert>
#include <iostream>

template<typename T>
Stack<T>::Stack(const Stack& other) {
    assert(other.elements != nullptr);
    delete[] elements;
    elements = new T[other._size];
    _size = other._size;
    _last = other._last;
    assert(elements != nullptr);
    for (int i = 0; i <= _last; i++) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Stack<T>::~Stack() {
    while (empty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T& element) {
    if (length() < _size) {
        elements[++_last] = element;
    } else {
        T* new_elements = new T[2*_size];
        _size = 2*_size;
        for (int i = 0; i <= _last; i++) {
            new_elements[i] = elements[i];
        }
        new_elements[++_last] = element;
        delete[] elements;
        elements = new_elements;
    }
}

template<typename T>
T& Stack<T>::pop() {
    assert(!empty());
    T result = elements[_last];
    elements[_last--] = 0;
    return result;
}

template<typename T>
T& Stack<T>::top() const {
    assert(!empty());
    return elements[_last];
}

template<typename T>
T& Stack<T>::operator[](const int& index) {
    assert(index >= 0 && index <= _last);
    return elements[index];
}