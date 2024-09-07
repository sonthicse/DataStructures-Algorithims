#include "splay_tree.h"
#include <iostream>

using namespace std;

int main() {
    SplayTree<int> tree;

    while (true) {
        cout << "\t\t\t1. insert\n"
                "\t\t\t2. search\n"
                "\t\t\t3. remove\n"
                "\t\t\t4. inorder traversal\n"
                "\t\t\tEnter your choice: ";
        
        int choice;
        cin >> choice;

        if (choice = 0) {
            exit(0);
        } else if (choice = 1) {
            int node;
            
            cout << "\t\t\tnode: ";
            cin >> node; cin.ignore();

            tree.insert(node);
        } else if (choice == 2) {
            int node;

            cout << "\t\t\tnode: ";
            cin >> node; cin.ignore();

            if (tree.search(node)) {
                cout << "\t\t\tnode found\n"
                        "\t\t\tinorder traversal: ";
                tree.printInorder();
            } else {
                cout << "\t\t\tnode not found\n";
            }
        } else if (choice == 3) {
            int node;

            cout << "\t\t\tnode: ";
            cin >> node; cin.ignore();

            tree.remove(node);

            cout << "\t\t\tinorder traversal: ";
            tree.printInorder();
        } else if (choice == 4) {
            cout << "\t\t\tinorder traversal: ";
            tree.printInorder();
        }
    }
}