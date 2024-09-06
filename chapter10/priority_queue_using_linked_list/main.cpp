#include <iostream>
#include "priority_queue.h"

using namespace std;

int main() {
    PriorityQueue<int, string> queue;

    while (true) {
        cout << "-----------------\n";
        cout << "1. Insert\n";
        cout << "2. Get Top\n";
        cout << "0. Exit\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        if (choice == 0) {
            exit(0);
        }

        if (choice == 1) {
            int key;
            string value;

            cout << "Enter Key: "; cin >> key; cin.ignore();
            cout << "Enter Value: "; getline(cin, value);

            queue.Insert(key, value);
        }

        if (choice == 2) {
            if (queue.getSize() > 0) {
                string result = "Key: " + to_string(*queue.getKeyMin()) + ", Value: " + *queue.getValueMin();
                cout << result << endl;
            } else {
                cout << "Queue is empty\n";
            }
        }
    }
}