#ifndef STACK_H
#define STACK_H

#include <iostream>

/**
 * @brief A templated stack implementation using a singly linked list.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template<typename T>
class Stack {
private:
    /**
     * @brief Node structure for the linked list.
     */
    struct Node {
        T data;       ///< The data stored in the node.
        Node* next;   ///< Pointer to the next node.

        /**
         * @brief Construct a new Node object.
         * 
         * @param value The value to be stored in the node.
         */
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;   ///< Pointer to the top of the stack.
    int _size;    ///< Number of elements in the stack.

public:
    /**
     * @brief Construct a new empty Stack object.
     */
    Stack() : head(nullptr), _size(0) {}

    /**
     * @brief Copy constructor.
     * 
     * @param other The stack to be copied.
     */
    Stack(const Stack& other);

    /**
     * @brief Destroy the Stack object.
     */
    ~Stack();

    /**
     * @brief Assignment operator.
     * 
     * @param other The stack to be assigned.
     * @return Stack& Reference to this stack.
     */
    Stack& operator=(const Stack& other);

    /**
     * @brief Check if the stack is empty.
     * 
     * @return true If the stack is empty.
     * @return false If the stack is not empty.
     */
    bool empty() const { return _size == 0; }

    /**
     * @brief Get the number of elements in the stack.
     * 
     * @return int The number of elements.
     */
    int size() const { return _size; }

    /**
     * @brief Push an element onto the stack.
     * 
     * @param value The value to be pushed.
     */
    void push(const T& value);

    /**
     * @brief Pop an element from the stack.
     * 
     * @return T The popped element.
     * @throw std::out_of_range If the stack is empty.
     */
    T pop();

    /**
     * @brief Get the top element of the stack without removing it.
     * 
     * @return const T& Reference to the top element.
     * @throw std::out_of_range If the stack is empty.
     */
    const T& top() const;

    /**
     * @brief Overloaded stream insertion operator for Stack.
     * 
     * @param os The output stream.
     * @param stack The stack to be printed.
     * @return std::ostream& Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        os << "[";
        for (Node* current = stack.head; current != nullptr; current = current->next) {
            os << current->data;
            if (current->next != nullptr) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

#include "stack.cpp"  // Include the implementation file

#endif // STACK_H