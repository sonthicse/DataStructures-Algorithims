#include <iostream>
#include "queue.h"

int main() {
    Queue<int> queue;
    for (int i = 0; i < 10; i++) {
        queue.enQueue(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << queue.deQueue() << " ";
    }
}