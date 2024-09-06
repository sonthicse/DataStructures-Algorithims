#include <iostream>
#include "list.h"

int main() {
    Circular_List<int> list;

    std::cout << "Inserting numbers 0 to 9:" << std::endl;
    for (int i = 0; i < 10; i++) {
        list.insert(i);
    }
    list.display();

    std::cout << "Size of the list: " << list.size() << std::endl;

    std::cout << "Removing number 5:" << std::endl;
    list.remove(5);
    list.display();

    std::cout << "Searching for number 3: " << (list.search(3) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for number 10: " << (list.search(10) ? "Found" : "Not found") << std::endl;

    std::cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    return 0;
}