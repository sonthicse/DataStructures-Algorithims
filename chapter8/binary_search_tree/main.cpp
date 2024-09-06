#include "tree.h"
#include <iostream>

using namespace std;

int main() {
    Tree<int> tree;

    while (true) {
        cout << "=====================\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. InorderTraversal\n";
        cout << "5. PreorderTraversal\n";
        cout << "6. PostorderTraversal\n";
        cout << "0. EXIT\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        int value;

        switch (choice) {
        case 0:
            
            exit(0);

        case 1:

            cout << "Enter Value: "; cin >> value; cin.ignore();
            tree.insert(value);
            break;

        case 2:

            cout << "Enter Value: "; cin >> value; cin.ignore();
            tree.remove(value);
            break;

        case 3:

            cout << "Enter Value: "; cin >> value; cin.ignore();
            cout << (tree.search(value) ? "Value: " + to_string(value) + " Found!\n" : "Value: " + to_string(value) + " Not found!\n");
            break;

        case 4:

            tree.inorder();
            cout << endl;
            break;

        case 5:

            tree.preorder();
            cout << endl;
            break;

        case 6:

            tree.postorder();
            cout << endl;
            break;
        }
    }
}