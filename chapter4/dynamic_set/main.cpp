#include <iostream>
#include "set.h"

using namespace std;

struct TestItem {
    int key;
    TestItem(int k = 0) : key(k) {}
    bool operator<(const TestItem& other) const { return key < other.key; }
    bool operator>(const TestItem& other) const { return key > other.key; }
    bool operator==(const TestItem& other) const { return key == other.key; }
};

ostream& operator<<(ostream& os, const TestItem& item) {
    return os << item.key;
}

int main() {
    set<TestItem> mySet;

    cout << "Inserting elements: 5, 2, 8, 1, 9, 2" << endl;
    mySet.setInsert(TestItem(5));
    mySet.setInsert(TestItem(2));
    mySet.setInsert(TestItem(8));
    mySet.setInsert(TestItem(1));
    mySet.setInsert(TestItem(9));
    mySet.setInsert(TestItem(2)); // Duplicate, should not be inserted

    cout << "Searching for 5: " << (mySet.Search(TestItem(5)) ? "Found" : "Not found") << endl;
    cout << "Searching for 7: " << (mySet.Search(TestItem(7)) ? "Found" : "Not found") << endl;

    try {
        cout << "Maximum element: " << mySet.max() << endl;
        cout << "Minimum element: " << mySet.min() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Deleting element 5" << endl;
    mySet.setDelete(TestItem(5));

    cout << "Searching for 5 after deletion: " << (mySet.Search(TestItem(5)) ? "Found" : "Not found") << endl;

    try {
        cout << "New maximum element: " << mySet.max() << endl;
        cout << "New minimum element: " << mySet.min() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}