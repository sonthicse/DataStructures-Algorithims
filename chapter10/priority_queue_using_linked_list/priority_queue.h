#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<typename Key, typename Value>
class Node {
private:
    Key key;
    Value value;
    Node* next;

public:
    Node(const Key& key, const Value& value) : key(key), value(value), next(nullptr) {}

    Key getKey() const { return key; }

    Value getValue() const { return value; }

    Node* getNext() const { return next; }

    void setNext(Node* node) { next = node; }
};

template<typename Key, typename Value>
class LinkedList {
private:
    Node<Key, Value>* head;
    int _size;

public:
    LinkedList() : head(nullptr), _size(0) {}

    int getSize() const { return _size; }

    void Insert(const Key& key, const Value& value);

    Node<Key, Value>* getMin() const { return head; }

    void Pop();
};

template<typename Key, typename Value>
class PriorityQueue {
private:
    LinkedList<Key, Value> priority_queue;

public:
    int getSize() const { return priority_queue.getSize(); }

    void Insert(const Key& key, const Value& value);

    void Pop();

    Key* getKeyMin() const;

    Value* getValueMin() const;
};

#include "priority_queue.cpp"

#endif