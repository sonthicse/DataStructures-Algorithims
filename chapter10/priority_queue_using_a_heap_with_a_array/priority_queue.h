#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define SIZE 100

template<class T>
class PriorityQueue {
private:
    T data[SIZE];
    int last;
    void shift_down(int i);

public:
    PriorityQueue() : last(-1) {}
    PriorityQueue(T* element, int n);
    bool empty() const { return last < 0; }
    T& findMin() const;
    void insert(const T& object, bool& suc);
    T deleteMin();
};

#include "priority_queue.cpp"

#endif