#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> stack;
    while (true) {
        cout << "Stack!\n";
        cout << "1. Append\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "0. Exit!\n";
        int choice;
        cout << "Enter choice: "; cin >> choice; cin.ignore();

        switch (choice) {
        case 0:
            exit(0);
        
        case 1:
            int number;
            cout << "Enter number: "; cin >> number; cin.ignore();
            stack.push(number);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            cout << "Stack: ";
            for (int i = 0; i < stack.length(); i++) {
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
    }
}