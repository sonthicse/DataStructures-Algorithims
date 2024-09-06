#include <iostream>
#include "list.h"

using namespace std;

void printList(const list<int>& l) {
    std::cout << "List: ";
    for (int i = 0; i < l.length(); ++i) {
        std::cout << l.get(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    list<int> myList;

    std::cout << "Testing empty list:" << std::endl;
    std::cout << "Is empty: " << (myList.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Length: " << myList.length() << std::endl;

    std::cout << "\nTesting append:" << std::endl;
    myList.append(10);
    myList.append(20);
    myList.append(30);
    printList(myList);

    std::cout << "\nTesting insert:" << std::endl;
    myList.insert(15, 1);
    printList(myList);

    std::cout << "\nTesting erase:" << std::endl;
    myList.erase(2);
    printList(myList);

    std::cout << "\nTesting get:" << std::endl;
    std::cout << "Element at index 1: " << myList.get(1) << std::endl;

    std::cout << "\nTesting iterator functions:" << std::endl;
    myList.start();
    while (myList.valid()) {
        std::cout << myList.getCurrent() << " ";
        myList.advanced();
    }
    std::cout << std::endl;

    std::cout << "\nTesting add:" << std::endl;
    myList.start();
    myList.advanced();
    myList.add(25);
    printList(myList);

    std::cout << "\nTesting remove:" << std::endl;
    myList.start();
    myList.advanced();
    myList.remove();
    printList(myList);

    return 0;
}