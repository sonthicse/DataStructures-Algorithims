#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

#define alpha 0.61803399

template<typename Key, typename Value>
class HashTable {
private:
    enum Status { occupied, empty, deleted};

    struct Entry {
        Key key;
        Value value;
        Status status;
    };

    std::vector<Entry> table;

    int _size;

    int _capacity;

    int hash(const Key& key) const;

    int probe(int hash, int i) const;

public:
    HashTable();

    ~HashTable();

    int size() const;
    
    int capacity() const;

    bool insert(const Key& key, const Value& value);

    bool remove(const Key& key);

    bool search(const Key& key, Value& value) const;

    void display() const;

};

#include "HashTable.cpp"

#endif