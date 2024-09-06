#include "priority_queue.h"
#include <cassert>

template<class T>
void PriorityQueue<T>::shift_down(int i) {
    T x = data[i];
    int parent = i;
    int child = 2*parent + 1;
    
    while (child <= last) {
        int right = child + 1;

        if (right <= last && data[right] < data[child]) {
            child = right;
        }
        
        if (x > data[child]) {
            data[parent] = data[child];
            child = 2*parent + 1;
        } else break;
    }

    data[parent] = x;
}

template<class T>
PriorityQueue<T>::PriorityQueue(T* element, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        data[i] = element[i];
    }

    last = n - 1;

    for (i = n/2 - 1; i >= 0; i--) {
        shift_down(i);
    }
}

template<class T>
T& PriorityQueue<T>::findMin() const {
    assert(last >= 0);
    
    return data[0];
}

template<class T>
T PriorityQueue<T>::deleteMin() {
    assert(last >= 0);
    T result = data[0];
    data[0] = data[last--];
    shift_down(0);
    
    return result;
}


template<class T>
void PriorityQueue<T>::insert(const T& object, bool& suc) {
    if (last = SIZE - 1) {
        suc = false;
    } else {
        suc = true;
        int child = ++last;

        while (child > 0) {
            int parent = (child - 1)/2;
            
            if (data[parent] > object) {
                data[child] = data[parent];
                child = parent;
            } else break;
        }

        data[child] = object;
    }
}