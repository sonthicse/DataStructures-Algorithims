#include <iostream>
#include "avl_tree.h"

using namespace std;

int main() {
    AVLTree<int> tree;

    while (true) {
        cout << "---------------------\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Remove\n";
        cout << "4. InOrderTraversal\n";
        cout << "0. Exit\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice;

        if (choice == 0) {
            exit(0);
        }

        if (choice == 1) {
            int key;
            cout << "Enter Key: "; cin >> key;
            tree.insert(key);
        }

        if (choice == 2) {
            int key;
            cout << "Enter Key: "; cin >> key;
            cout << (tree.search(key) ? "Key found\n" : "Key not found\n");
        }

        if (choice == 3) {
            int key;
            cout << "Enter Key: "; cin >> key;
            tree.remove(key);
        }

        if (choice == 4) {
            tree.inOrder();
            cout << endl;
        }
    }
}