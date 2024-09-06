#include "HashTable.h"
#include <iostream>
#include <string>

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(): table(811) {
    for (auto& entry : table) {
        entry.status = empty;
    }

    _size = 0;
}

template<typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    for (auto& entry : table) {
        entry.status = empty;
    }

    _size = 0;
}

template<typename Key, typename Value>
int HashTable<Key, Value>::size() const {
    return _size;
}

template<typename Key, typename Value>
int HashTable<Key, Value>::capacity() const {
    return table.size();
}

template<typename Key, typename Value>
int HashTable<Key, Value>::hash(const Key& key) const {
    return (int) (alpha*key - (int) alpha*key)*table.size();
}

template<typename Key, typename Value>
int HashTable<Key, Value>::probe(int hash, int i) const {
    return (hash + i*i)%table.size();
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::insert(const Key& key, const Value& value) {
    for (int i = 0; i < table.size(); i++) {
        int index = probe(hash(key), i);
        
        if (table[index].status != occupied) {
            table[index].key = key;
            table[index].value = value;
            table[index].status = occupied;
            _size++;
            
            return true;
        }
    }

    return false;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key& key) {
    for (int i = 0; i < table.size(); i++) {
        int index = probe(hash(key), i);
        if (table[index].status == empty) {
            return false;
        }
        if (table[index].status == occupied && table[index].key == key) {
            table[index].status = deleted;
            _size--;
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::search(const Key& key, Value& value) const {
    for (int i = 0; i < table.size(); i++) {
        int index = probe(hash(key), i);
        if (table[index].status == empty) {
            return false;
        }
        if (table[index].status == occupied && table[index].key == key) {
            value = table[index].value;
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::display() const {
    std::string result = "{";
    bool first = true;
    for (const auto& entry : table) {
        if (entry.status == occupied) {
            if (!first) {
                result += ", ";
            }
            result += '"' + std::to_string(entry.key) + '"' + ": " + std::to_string(entry.value);
            first = false;
        }
    }
    result += "}";
    std::cout << result;
}