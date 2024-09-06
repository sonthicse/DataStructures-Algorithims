#include "rb_tree.h"
#include <iostream>

void printTreeStatus(RedBlackTree<int>& tree, const std::string& operation) {
    std::cout << "\nAfter " << operation << ":" << std::endl;
    tree.printInorder();
}

int main() {
    RedBlackTree<int> tree;

    // Test insertion
    std::cout << "Inserting elements: 10, 20, 30, 15, 25, 5, 35" << std::endl;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(35);
    printTreeStatus(tree, "insertion");

    // Test search
    int searchValue = 15;
    std::cout << "\nSearching for " << searchValue << ": " 
              << (tree.search(searchValue) ? "Found" : "Not found") << std::endl;
    
    searchValue = 40;
    std::cout << "Searching for " << searchValue << ": " 
              << (tree.search(searchValue) ? "Found" : "Not found") << std::endl;

    // Test deletion
    int deleteValue = 20;
    std::cout << "\nDeleting " << deleteValue << std::endl;
    tree.remove(deleteValue);
    printTreeStatus(tree, "deletion of " + std::to_string(deleteValue));

    deleteValue = 5;
    std::cout << "\nDeleting " << deleteValue << std::endl;
    tree.remove(deleteValue);
    printTreeStatus(tree, "deletion of " + std::to_string(deleteValue));

    deleteValue = 35;
    std::cout << "\nDeleting " << deleteValue << std::endl;
    tree.remove(deleteValue);
    printTreeStatus(tree, "deletion of " + std::to_string(deleteValue));

    return 0;
}