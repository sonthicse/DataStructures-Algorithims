#include <iostream>
#include <string>
#include "stack.h"

void testIntStack() {
    std::cout << "Testing int Stack:" << std::endl;
    Stack<int> s;
    
    // Test push and size
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Size after pushing 3 elements: " << s.size() << std::endl;
    
    // Test pop
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Size after pop: " << s.size() << std::endl;
    
    // Test copy constructor
    Stack<int> s2 = s;
    std::cout << "Size of copied stack: " << s2.size() << std::endl;
    
    // Test assignment operator
    Stack<int> s3;
    s3 = s;
    std::cout << "Size of assigned stack: " << s3.size() << std::endl;
    
    // Test operator[]
    std::cout << "Element at index 0: " << s[0] << std::endl;
    
    // Test empty
    while (!s.empty()) {
        s.pop();
    }
    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;
    
    // Test exception handling
    try {
        s.pop();
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testStringStack() {
    std::cout << "\nTesting string Stack:" << std::endl;
    Stack<std::string> s;
    
    s.push("Hello");
    s.push("World");
    std::cout << "Size after pushing 2 strings: " << s.size() << std::endl;
    
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Remaining element: " << s[0] << std::endl;
}

int main() {
    testIntStack();
    testStringStack();
    return 0;
}