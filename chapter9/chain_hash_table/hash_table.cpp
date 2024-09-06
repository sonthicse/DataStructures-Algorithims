#include "hash_table.h"
#include <cmath>

template<typename Key, typename Value>
LinkedList<Key, Value>::~LinkedList() {
    HashNode<Key, Value>* current = head;

    while (current != nullptr) {
        HashNode<Key, Value>* temp = current;
        current = current->getNext();
        delete temp;
    }
}

template<typename Key, typename Value>
void LinkedList<Key, Value>::Insert(const Key& key, const Value& value) {
    HashNode<Key, Value>* newNode = Find(key);

    if (newNode != nullptr) return;

    newNode = new HashNode<Key, Value>(key, value);
    newNode->setNext(head);
    head = newNode;
}

template<typename Key, typename Value>
HashNode<Key, Value>* LinkedList<Key, Value>::Find(const Key& key) const {
    HashNode<Key, Value>* current = head;

    while (current != nullptr) {

        if (key == current->getKey()) return current;

        current = current->getNext();
    }

    return current;
}

template<typename Key, typename Value>
bool LinkedList<Key, Value>::Remove(const Key& key) {
    if (key == head->getKey()) {
        HashNode<Key, Value>* temp = head;
        head = head->getNext();
        delete temp;

        return true;
    }

    HashNode<Key, Value>* current = head;
    HashNode<Key, Value>* previous = nullptr;

    while (current != nullptr) {
        previous = current;
        current = current->getNext();

        if (key == current->getKey()) {
            previous->setNext(current->getNext());
            delete current;

            return true;
        }
    }

    return false;
}

template<typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    for (int i = 0; i < _capacity; i++) {
        buckets[i].~LinkedList();
    }
}

template<typename Key, typename Value>
int HashTable<Key, Value>::Hash(Key key) {
    return std::floor(_capacity*(alpha*key - std::floor(alpha*key)));
}

template<typename Key, typename Value>
void HashTable<Key, Value>::Insert(const Key& key, const Value& value) {
    int index = Hash(key);
    buckets[index].Insert(key, value);
}

template<typename Key, typename Value>
Value* HashTable<Key, Value>::Find(const Key& key) {
    int index = Hash(key);
    Value* value = new Value;

    if (buckets[index].Find(key) != nullptr) {
        *value = buckets[index].Find(key)->getValue();

        return value;
    }

    return nullptr;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::Remove(const Key& key) {
    int index = Hash(key);

    return (buckets[index].getHead() != nullptr) ? buckets[index].Remove(key) : false;
}