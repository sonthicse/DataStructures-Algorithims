#include "skew_heap.h"
#include "iostream"

using namespace std;

int main() {
    SkewHeap<int> skewHeap;

    while (true) {
        cout << "1. insert\n"
                "2. find min\n"
                "3. delete min\n"
                "4. inOrder traversal\n"
                "0. exit\n";

        int choice;

        cout << "enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            exit(0);
        } else if (choice == 1) {
            int value;

            cout << "value: ";
            cin >> value;

            skewHeap.insert(value);
        } else if (choice == 2) {
            if (!skewHeap.isEmpty()) {
                cout << "min value: " << skewHeap.findMin() << endl;
            } else {
                cout << "skew heap is empty\n";
            }
        } else if (choice == 3) {
            skewHeap.deleteMin();
            
            cout << "inOrder traversal: ";
            skewHeap.printInOrder();
        } else if (choice == 4) {
            cout << "inOrder traversal: ";
            skewHeap.printInOrder();
        }
    }
}