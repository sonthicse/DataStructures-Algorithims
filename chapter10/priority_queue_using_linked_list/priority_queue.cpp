#include "priority_queue.h"

template<typename Key, typename Value>
void LinkedList<Key, Value>::Insert(const Key& key, const Value& value) {
    _size++;
    Node<Key, Value>* newNode = new Node<Key, Value>(key, value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    if (key < head->getKey()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node<Key, Value>* current = head;
    Node<Key, Value>* previous = nullptr;

    while (current != nullptr) {
        previous = current;
        current = current->getNext();

        if (key < current->getKey()) {
            newNode->setNext(current);
            previous->setNext(newNode);
            return;
        }
    }

    previous->setNext(newNode);
}

template<typename Key, typename Value>
void LinkedList<Key, Value>::Pop() {
    Node<Key, Value>* temp = head;
    head = head->getNext();
    delete temp;
    _size--;
}

template<typename Key, typename Value>
void PriorityQueue<Key, Value>::Insert(const Key& key, const Value& value) {
    priority_queue.Insert(key, value);
}

template<typename Key, typename Value>
void PriorityQueue<Key, Value>::Pop() {
    priority_queue.Pop();
}

template<typename Key, typename Value>
Key* PriorityQueue<Key, Value>::getKeyMin() const {
    if (priority_queue.getMin() == nullptr) return nullptr;

    Key* key = new Key;
    *key = priority_queue.getMin()->getKey();

    return key;
}

template<typename Key, typename Value>
Value* PriorityQueue<Key, Value>::getValueMin() const {
    if (priority_queue.getMin() == nullptr) return nullptr;

    Value* value = new Value;
    *value = priority_queue.getMin()->getValue();

    return value;
}