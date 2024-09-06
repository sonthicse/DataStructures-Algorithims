#include <iostream>
#include "hash_table.h"

using namespace std;

int main() {
    HashTable<int, int> hash;
    
    while (true) {
        cout << "--------------------\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "0. Exit\n";

        int choice;
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        if (choice == 0) {
            exit(0);
        }

        if (choice == 1) {
            int key, value;

            cout << "Enter Key: "; cin >> key;
            cout << "Enter Value: "; cin >> value;
            cin.ignore();

            hash.Insert(key, value);
        }

        if (choice == 2) {
            int key;

            cout << "Enter Key: "; cin >> key; cin.ignore();
            cout << (hash.Remove(key) ? "Key remove successfully\n" : "Key not found\n");
        }

        if (choice == 3) {
            int key;
            int* value;

            cout << "Enter Key: "; cin >> key; cin.ignore();
            value = hash.Find(key);
            cout << (value != nullptr ? "Key: " + to_string(key) + ", Value: " + to_string(*value) : "Key not found");
            cout << endl;
        }
    }
}