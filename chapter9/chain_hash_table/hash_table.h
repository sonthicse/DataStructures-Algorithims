#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define alpha 0.61803399

template<typename Key, typename Value>
class HashNode {
private:
    Key key;
    Value value;
    HashNode* next;

public:
    HashNode(const Key& k, const Value& v) : key(k), value(v) {}

    Key getKey() const { return key; }

    Value getValue() const { return value; }

    HashNode* getNext() const { return next; }

    void setNext(HashNode* node) { next = node; }
};

template<typename Key, typename Value>
class LinkedList {
private:
    HashNode<Key, Value>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList();

    HashNode<Key, Value>* getHead() const { return head; }

    void Insert(const Key& key, const Value& value);
    HashNode<Key, Value>* Find(const Key& key) const;
    bool Remove(const Key& key);
};

template<typename Key, typename Value>
class HashTable {
private:
    LinkedList<Key, Value>* buckets;
    int _capacity;
    int _size;

    int Hash(Key key);

public:
    HashTable(int capacity = 100) : buckets(new LinkedList<Key, Value>[capacity]), _capacity(capacity), _size(0) {}

    ~HashTable();

    void Insert(const Key& key, const Value& value);

    Value* Find(const Key& key);

    bool Remove(const Key& key);

    int size() const { return _size; }
};

#include "hash_table.cpp"

#endif