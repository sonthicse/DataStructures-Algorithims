#include <iostream>
#include "dynamic_list.h"
#include "dynamic_list.cpp"

void printList(const dynamic_list<int>& list) {
    std::cout << "List contents: ";
    for (int i = 0; i < list.length(); ++i) {
        std::cout << list.getElement(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test constructor and append
    dynamic_list<int> myList;
    std::cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << std::endl;
    
    myList.append(10);
    myList.append(20);
    myList.append(30);
    
    std::cout << "After appending 10, 20, 30:" << std::endl;
    printList(myList);
    
    // Test insert
    myList.insert(15, 1);
    std::cout << "After inserting 15 at index 1:" << std::endl;
    printList(myList);
    
    // Test erase
    myList.erase(2);
    std::cout << "After erasing element at index 2:" << std::endl;
    printList(myList);
    
    // Test copy constructor
    dynamic_list<int> copiedList(myList);
    std::cout << "Copied list:" << std::endl;
    printList(copiedList);
    
    // Test assignment operator
    dynamic_list<int> assignedList;
    assignedList = myList;
    std::cout << "Assigned list:" << std::endl;
    printList(assignedList);
    
    // Test iterator
    std::cout << "Using iterator to traverse the list:" << std::endl;
    dynamic_list_iterator<int> it(myList);
    for (it.start(); it.valid(); it.advance()) {
        std::cout << it.get_current() << " ";
    }
    std::cout << std::endl;
    
    // Test iterator add and remove
    it.start();
    it.add(5);
    std::cout << "After adding 5 at the beginning using iterator:" << std::endl;
    printList(myList);
    
    it.advance();
    it.remove();
    std::cout << "After removing the second element using iterator:" << std::endl;
    printList(myList);
    
    return 0;
}