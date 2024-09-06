#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable<int, int> dict;

    while (true) {
        cout << "-------------------------\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "0. EXIT\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        int key;
        int value;

        switch (choice) {
        case 0:
            exit(0);

        case 1:

            cout << "Enter Key: "; cin >> key;
            cout << "Enter Value: "; cin >> value; cin.ignore();
            cout << (dict.insert(key, value) ? "Object inserted successfully!\n" : "Object insert failed\n");

            break;

        case 2:
            
            cout << "Enter Key: "; cin >> key; cin.ignore();
            cout << (dict.remove(key) ? "Object removed successfully\n" : "Object remove failed\n");
        
            break;

        case 3:

            cout << "Enter Key: "; cin >> key; cin.ignore();
            cout << (dict.search(key, value) ? "Key: '" + to_string(key)+ "'" + ", Value: " + to_string(value) + "\n" : "Key not found\n");
        
            break;

        case 4:

            dict.display();
            cout << endl;
        
            break;
        }
    }
}