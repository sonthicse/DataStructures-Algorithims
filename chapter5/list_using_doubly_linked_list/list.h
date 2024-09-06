// double linked list

#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int _size;

public:
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        Iterator& operator--() { current = current->prev; return *this; }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    List() : head(nullptr), tail(nullptr), _size(0) {}

    ~List() { clear(); }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        _size++;
    }

    void push_front(const T& data) {
        Node* newNode = new Node(data);
        if(empty()) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        _size++;
    }

    void pop_back() {
        if (_size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        _size--;
    }

    void pop_front() {
        if (_size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        _size--;
    }

    Iterator insert(Iterator pos, const T& data) {
        if (pos == begin()) {
            push_front(data);
            return begin;
        }
        if (pos == end()) {
            push_back(data);
            return --end();
        }
        Node* newNode = new Node(data);
        Node* current = pos.current;
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        _size++;
        return Iterator(newNode);
    }

    Iterator erase(Iterator pos) {
        if (empty() || pos == end()) return end();
        Node* current = pos.current;
        if (current == head) {
            pop_front();
            return begin();
        }
        if (current == tail) {
            pop_back();
            return end();
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Iterator result(current->next);
        delete current;
        _size--;
        return result;
    }

    void clear() {
        while (empty()) {
            pop_back();
        }
    }

    int size() const { return _size; }

    bool empty() const { return _size == 0; }

    Iterator begin() { return Iterator(head); }

    Iterator end() { return Iterator(nullptr); }
};

#endif