#ifndef SET_H
#define SET_H

#include "list.h"

/**
 * @brief Template class for a set implemented using a doubly linked list.
 * 
 * This class implements a set data structure, ensuring that each element
 * appears only once in the collection.
 * 
 * @tparam T The type of elements stored in the set.
 */
template<typename T>
class Set {
private:
    List<T> list;  ///< Internal list to store the set elements.

public:
    /**
     * @brief Construct a new empty Set object.
     */
    Set() : list() {}

    /**
     * @brief Add a new element to the set if it doesn't already exist.
     * 
     * @param value The value to be added to the set.
     */
    void append(const T& value) {
        if (!search(value)) {
            list.push_back(value);
        }
    }

    /**
     * @brief Remove an element from the set if it exists.
     * 
     * @param value The value to be removed from the set.
     */
    void erase(const T& value) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == value) {
                list.erase(it);
                return;
            }
        }
    }

    /**
     * @brief Get the number of elements in the set.
     * 
     * @return The number of elements in the set.
     */
    int length() const { return list.length(); }

    /**
     * @brief Check if a value exists in the set.
     * 
     * @param value The value to search for.
     * @return true if the value is found in the set, false otherwise.
     */
    bool search(const T& value) const {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == value) return true;
        }
        return false;
    }

    /**
     * @brief Access an element at a specific index in the set.
     * 
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     * @throw std::out_of_range if the index is out of bounds.
     */
    T& operator[](int index) {
        return list[index];
    }

    /**
     * @brief Get a constant reference to an element at a specific index in the set.
     * 
     * @param index The index of the element to access.
     * @return Constant reference to the element at the specified index.
     * @throw std::out_of_range if the index is out of bounds.
     */
    const T& operator[](int index) const {
        return list[index];
    }

    /**
     * @brief Get an iterator pointing to the first element of the set.
     * 
     * @return Iterator to the beginning of the set.
     */
    typename List<T>::Iterator begin() { return list.begin(); }

    /**
     * @brief Get an iterator pointing to the position one past the last element of the set.
     * 
     * @return Iterator to the end of the set.
     */
    typename List<T>::Iterator end() { return list.end(); }

    /**
     * @brief Get a const iterator pointing to the first element of the set.
     * 
     * @return ConstIterator to the beginning of the set.
     */
    typename List<T>::ConstIterator begin() const { return list.begin(); }

    /**
     * @brief Get a const iterator pointing to the position one past the last element of the set.
     * 
     * @return ConstIterator to the end of the set.
     */
    typename List<T>::ConstIterator end() const { return list.end(); }
};

#endif