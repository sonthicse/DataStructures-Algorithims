#include "Bag.h"
#include <iostream>

using namespace std;

void printBag(const Bag& bag) {
    cout << "Bag size: " << bag.sum() << endl;
    cout << "Contents: ";
    for (int i = 1; i <= 10; i++) {
        cout << i << "(" << bag.occurr(i) << ") ";
    }
    cout << endl;
}

int main() {
    Bag bag1, bag2;

    // Test insert
    cout << "Testing insert:" << endl;
    for (int i = 1; i <= 5; i++) {
        bag1.insert(i);
        bag1.insert(i);
    }
    printBag(bag1);

    // Test remove
    cout << "\nTesting remove:" << endl;
    bag1.remove(3);
    printBag(bag1);

    // Test occurr
    cout << "\nTesting occurr:" << endl;
    cout << "Occurrences of 2: " << bag1.occurr(2) << endl;
    cout << "Occurrences of 3: " << bag1.occurr(3) << endl;

    // Test operator+=
    cout << "\nTesting operator+=:" << endl;
    for (int i = 6; i <= 8; i++) {
        bag2.insert(i);
    }
    cout << "bag2: ";
    printBag(bag2);
    bag1 += bag2;
    cout << "bag1 after += bag2: ";
    printBag(bag1);

    // Test operator+
    cout << "\nTesting operator+:" << endl;
    Bag bag3 = bag1 + bag2;
    cout << "bag3 (bag1 + bag2): ";
    printBag(bag3);

    return 0;
}

Bag::Bag() : size(0) {}

int Bag::sum() const { return size; }

int Bag::occurr(const Item& element) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == element) count++;
    }
    return count;
}

void Bag::insert(const Item& element) {
    if (size < MAX_SIZE)
        data[size++] = element;
}

void Bag::remove(const Item& element) {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) {
            data[i] = data[size - 1];
            size--;
            return;
        }
    }
}

void Bag::operator+=(const Bag& bag) {
    for (int i = size; i < bag.size; i++) {
        data[i] = bag.data[i - size];
    }
    size += bag.size;
}

Bag operator+(const Bag& bag1, const Bag& bag2) {
    Bag bag;
    bag += bag1;
    bag += bag2;
    return bag;
}