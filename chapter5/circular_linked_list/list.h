#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
class Circular_List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int _size;

public:
    Circular_List() : head(nullptr), _size(0) {}

    ~Circular_List() {
        if (head == nullptr) return;
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
        _size++;
    }

    void remove(const T& value) {
        if (head == nullptr) return;
        
        if (head->data == value) {
            if (_size == 1) {
                delete head;
                head = nullptr;
            } else {
                Node* last = head;
                while (last->next != head) last = last->next;
                Node* temp = head;
                head = head->next;
                last->next = head;
                delete temp;
            }
            _size--;
            return;
        }

        Node* current = head;
        while (current->next != head && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next != head) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            _size--;
        }
    }

    bool search(const T& value) const {
        if (head == nullptr) return false;
        Node* current = head;
        do {
            if (current->data == value) return true;
            current = current->next;
        } while (current != head);
        return false;
    }

    int size() const { return _size; }

    bool empty() const { return _size == 0; }

    void display() const {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

#endif