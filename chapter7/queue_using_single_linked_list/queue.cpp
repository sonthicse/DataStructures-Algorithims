#include "queue.h"
#include <stdexcept>

template<typename T>
Queue<T>::Queue(const Queue& other) : head(nullptr), tail(nullptr), _size(0) {
    for (Node* current = other.head; current != nullptr; current = current->next) {
        enQueue(current->data);
    }
}

template<typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        deQueue();
    }
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if (this != &other) {
        // Clear existing queue
        while (!empty()) {
            deQueue();
        }

        // Copy elements from other queue
        for (Node* current = other.head; current != nullptr; current = current->next) {
            enQueue(current->data);
        }
    }
    return *this;
}

template<typename T>
void Queue<T>::enQueue(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    _size++;
}

template<typename T>
T Queue<T>::deQueue() {
    if (empty()) {
        throw std::runtime_error("Cannot dequeue from an empty queue");
    }
    T result = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    _size--;
    if (empty()) {
        tail = nullptr;
    }
    return result;
}

template<typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return head->data;
}

template<typename T>
T& Queue<T>::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
const T& Queue<T>::operator[](int index) const {
    return const_cast<Queue<T>*>(this)->operator[](index);
}