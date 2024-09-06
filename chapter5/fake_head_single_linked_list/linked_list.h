#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
class Linked_List {
private:
    class Node {
    private:
        T data;
        Node* next;

    public:
        friend class Linked_List;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int _size;

public:
    Linked_List() : head(new Node(T())), tail(nullptr), _size(0) {}

    ~Linked_List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const { return _size == 0; }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        _size++;
    }

    void insert(const T& value, const int& index) {
        if (index < 0 || index > _size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            push_front(value);
        } else if (index == _size) {
            push_back(value);
        } else {
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            _size++;
        }
    }

    void pop_front() {
        if (empty()) return;
        Node* temp = head->next;
        head->next = temp->next;
        if (tail == temp) {
            tail = head;
        }
        delete temp;
        _size--;
    }

    void pop_back() {
        if (empty()) return;
        if (_size == 1) {
            delete head->next;
            head->next = nullptr;
            tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        _size--;
    }

    T& operator[](const int& index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};

#endif