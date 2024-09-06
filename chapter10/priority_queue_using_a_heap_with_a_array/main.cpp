#include "priority_queue.h"
#include <iostream>

using namespace std;

int main() {
    PriorityQueue<int> queue;

    while (true) {
        cout << "------------------\n";
        cout << "1. Insert\n";
        cout << "2. Pop\n";
        cout << "4. Exit\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        if (choice == 0) {
            exit(0);
        }

        if (choice == 1) {
            int priority;
            bool suc;
            cout << "Enter Priority: "; cin >> priority; cin.ignore();

            queue.insert(priority, suc);

            if (suc) {
                cout << "Priority inserted successfully\n";
            }
        }

        if (choice == 2) {
            if (!queue.empty()) {
                int priority = queue.deleteMin();
                string result = "Priority: " + to_string(priority) + "\nPriority removed successfully\n";
                cout << result;
            } else {
                cout << "Queue is empty\n";
            }
        }
    }

    return 0;
}