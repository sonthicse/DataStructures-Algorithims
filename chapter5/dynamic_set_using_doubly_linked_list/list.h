#ifndef LIST_H
#define LIST_H

#include <cassert>

/**
 * @brief Template class for a doubly linked list.
 * 
 * This class implements a doubly linked list with various operations
 * such as insertion, deletion, and traversal.
 * 
 * @tparam T The type of elements stored in the list.
 */
template<typename T>
class List {
private:
    /**
     * @brief Node class for the linked list.
     * 
     * Each node contains the data and pointers to the previous and next nodes.
     */
    class Node {
    private:
        T data;
        Node* previous;
        Node* next;

    public:
        friend class List;

        /**
         * @brief Construct a new Node object.
         * 
         * @param value The value to be stored in the node.
         */
        Node(const T& value) : data(value), previous(nullptr), next(nullptr) {}
    };

    Node* head;    ///< Pointer to the first node in the list.
    Node* tail;    ///< Pointer to the last node in the list.
    int _length;   ///< Number of elements in the list.

public:
    /**
     * @brief Iterator class for the List.
     * 
     * Allows for traversal of the list in both directions.
     */
    class Iterator {
    private:
        Node* current;

    public:
        friend class List;

        Iterator(Node* node) : current(node) {}

        T& operator*() const { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        Iterator& operator--() { current = current->previous; return *this; }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    /**
     * @brief Const Iterator class for the List.
     * 
     * Allows for read-only traversal of the list in both directions.
     */
    class ConstIterator {
    private:
        const Node* current;

    public:
        ConstIterator(const Node* node) : current(node) {}

        const T& operator*() const { return current->data; }
        ConstIterator& operator++() { current = current->next; return *this; }
        ConstIterator& operator--() { current = current->previous; return *this; }
        bool operator==(const ConstIterator& other) const { return current == other.current; }
        bool operator!=(const ConstIterator& other) const { return current != other.current; }
    };

    /**
     * @brief Construct a new empty List object.
     */
    List() : head(nullptr), tail(nullptr), _length(0) {}

    /**
     * @brief Destroy the List object and free all allocated memory.
     */
    ~List() { clear(); }

    /**
     * @brief Check if the list is empty.
     * 
     * @return true if the list is empty, false otherwise.
     */
    bool empty() const { return _length == 0; }

    /**
     * @brief Get the number of elements in the list.
     * 
     * @return The number of elements.
     */
    int length() const { return _length; }

    /**
     * @brief Insert an element at the beginning of the list.
     * 
     * @param value The value to be inserted.
     */
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        _length++;
    }

    /**
     * @brief Insert an element at the end of the list.
     * 
     * @param value The value to be inserted.
     */
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
        _length++;
    }

    /**
     * @brief Insert an element at a specific position in the list.
     * 
     * @param position Iterator pointing to the position where the element should be inserted.
     * @param value The value to be inserted.
     * @return Iterator pointing to the newly inserted element.
     */
    Iterator insert(const Iterator& position, const T& value) {
        if (position == begin()) {
            push_front(value);
            return begin();
        }
        if (position == end()) {
            push_back(value);
            return --end();
        }
        Node* newNode = new Node(value);
        Node* current = position.current;
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous->next = newNode;
        current->previous = newNode;
        _length++;
        return Iterator(newNode);
    }

    /**
     * @brief Remove the first element from the list.
     */
    void pop_front() {
        if(empty()) return;
        if (_length == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->previous = nullptr;
            delete temp;
        }
        _length--;
    }

    /**
     * @brief Remove the last element from the list.
     */
    void pop_back() {
        if (empty()) return;
        if (_length == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;
        }
        _length--;
    }

    /**
     * @brief Remove all elements from the list.
     */
    void clear() {
        while (!empty()) pop_back();
    }

    /**
     * @brief Remove an element at a specific position in the list.
     * 
     * @param position Iterator pointing to the element to be removed.
     * @return Iterator pointing to the element following the erased element.
     */
    Iterator erase(const Iterator& position) {
        if (empty() || position == end()) return end();
        Node* current = position.current;
        if (current == head) {
            pop_front();
            return begin();
        }
        if (current == tail) {
            pop_back();
            return end();
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        Iterator result(current->next);
        delete current;
        _length--;
        return result;
    }

    /**
     * @brief Get an iterator pointing to the first element of the list.
     * 
     * @return Iterator to the beginning of the list.
     */
    Iterator begin() { return Iterator(head); }

    /**
     * @brief Get an iterator pointing to the position one past the last element of the list.
     * 
     * @return Iterator to the end of the list.
     */
    Iterator end() { return Iterator(nullptr); }

    /**
     * @brief Get a const iterator pointing to the first element of the list.
     * 
     * @return ConstIterator to the beginning of the list.
     */
    ConstIterator begin() const { return ConstIterator(head); }

    /**
     * @brief Get a const iterator pointing to the position one past the last element of the list.
     * 
     * @return ConstIterator to the end of the list.
     */
    ConstIterator end() const { return ConstIterator(nullptr); }

    /**
     * @brief Access an element at a specific index in the list.
     * 
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     * @throw std::out_of_range if the index is out of bounds.
     */
    T& operator[](int index) {
        if (index < 0 || index >= _length) {
            throw std::out_of_range("Index out of bounds");
        }
        auto it = begin();
        for (int i = 0; i < index; i++, ++it);
        return *it;
    }

    /**
     * @brief Get a constant reference to an element at a specific index in the list.
     * 
     * @param index The index of the element to access.
     * @return Constant reference to the element at the specified index.
     * @throw std::out_of_range if the index is out of bounds.
     */
    const T& operator[](int index) const {
        if (index < 0 || index >= _length) {
            throw std::out_of_range("Index out of bounds");
        }
        auto it = begin();
        for (int i = 0; i < index; i++, ++it);
        return *it;
    }
};

#endif