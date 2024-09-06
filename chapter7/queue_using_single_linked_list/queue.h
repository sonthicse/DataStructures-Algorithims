/**
 * @file queue.h
 * @brief Contains the definition of the Queue class.
 * @author SonThi
 * @date 2024-08-15
 */

#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief A template class for a Queue data structure implemented using a linked list.
 *
 * This class provides a basic implementation of a queue with operations like enqueue,
 * dequeue, and checking if the queue is empty. It uses a singly linked list for internal
 * storage, allowing for efficient insertion at the back and removal from the front.
 *
 * @tparam T The type of elements stored in the queue.
 *
 * @note This implementation is not thread-safe. External synchronization is required
 *       for concurrent access.
 *
 * Example usage:
 * @code
 * Queue<int> myQueue;
 * myQueue.enQueue(5);
 * myQueue.enQueue(10);
 * int front = myQueue.front(); // Returns 5
 * int dequeued = myQueue.deQueue(); // Returns 5, queue now contains only 10
 * @endcode
 */
template<typename T>
class Queue {
private:
    /**
     * @brief Internal node structure for the linked list.
     */
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;  ///< Pointer to the front of the queue
    Node* tail;  ///< Pointer to the back of the queue
    int _size;   ///< Number of elements in the queue

public:
    /**
     * @brief Default constructor.
     */
    Queue() : head(nullptr), tail(nullptr), _size(0) {}

    /**
     * @brief Copy constructor.
     * @param other The queue to be copied.
     */
    Queue(const Queue& other);

    /**
     * @brief Destructor.
     */
    ~Queue();

    /**
     * @brief Assignment operator.
     * @param other The queue to be assigned.
     * @return Reference to this queue.
     */
    Queue& operator=(const Queue& other);

    /**
     * @brief Check if the queue is empty.
     * @return true if the queue is empty, false otherwise.
     */
    bool empty() const { return _size == 0; }

    /**
     * @brief Get the number of elements in the queue.
     * @return The size of the queue.
     */
    int size() const { return _size; }

    /**
     * @brief Add an element to the back of the queue.
     * @param value The value to be added.
     */
    void enQueue(const T& value);

    /**
     * @brief Remove and return the element at the front of the queue.
     * @return The value at the front of the queue.
     * @throw std::runtime_error if the queue is empty.
     */
    T deQueue();

    /**
     * @brief Get a reference to the element at the front of the queue without removing it.
     * @return Reference to the front element.
     * @throw std::runtime_error if the queue is empty.
     */
    const T& front() const;

    /**
     * @brief Access operator (for testing purposes only, not typical for a queue).
     * @param index The index of the element to access.
     * @return Reference to the element at the given index.
     * @throw std::out_of_range if the index is out of bounds.
     */
    T& operator[](int index);
    const T& operator[](int index) const;
};

#include "queue.cpp"

#endif // QUEUE_H