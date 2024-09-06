#include <iostream>
#include <stdexcept>
#include "stack.h"

/**
 * @brief Move a disk from one stack to another.
 * 
 * @tparam T The type of elements in the stack.
 * @param from The stack to move from.
 * @param to The stack to move to.
 * @param fromName The name of the 'from' stack.
 * @param toName The name of the 'to' stack.
 */
template<typename T>
void moveDisk(Stack<T>& from, Stack<T>& to, const std::string& fromName, const std::string& toName) {
    if (from.empty()) {
        throw std::runtime_error("Cannot move from an empty stack");
    }
    T disk = from.pop();
    to.push(disk);
    std::cout << "Move disk " << disk << " from " << fromName << " to " << toName << std::endl;
}

/**
 * @brief Solve the Tower of Hanoi puzzle.
 * 
 * @tparam T The type of elements in the stack.
 * @param n The number of disks to move.
 * @param source The source stack.
 * @param auxiliary The auxiliary stack.
 * @param destination The destination stack.
 * @param sourceName The name of the source stack.
 * @param auxiliaryName The name of the auxiliary stack.
 * @param destinationName The name of the destination stack.
 */
template<typename T>
void hanoi_tower(int n, Stack<T>& source, Stack<T>& auxiliary, Stack<T>& destination,
                 const std::string& sourceName, const std::string& auxiliaryName, const std::string& destinationName) {
    if (n == 1) {
        moveDisk(source, destination, sourceName, destinationName);
        std::cout << source << "\n" << auxiliary << "\n" << destination << "\n";
    } else {
        hanoi_tower(n - 1, source, destination, auxiliary, sourceName, destinationName, auxiliaryName);
        moveDisk(source, destination, sourceName, destinationName);
        std::cout << source << "\n" << auxiliary << "\n" << destination << "\n";
        hanoi_tower(n - 1, auxiliary, source, destination, auxiliaryName, sourceName, destinationName);
    }
}

/**
 * @brief Initialize and solve the Tower of Hanoi puzzle.
 * 
 * @tparam T The type of elements in the stack.
 * @param n The number of disks.
 */
template<typename T>
void solve_hanoi_tower(int n) {
    Stack<T> source, auxiliary, destination;

    // Initialize the source stack with n disks
    for (int i = n; i > 0; --i) {
        source.push(static_cast<T>(i));
    }

    std::cout << "Initial state:" << std::endl;
    std::cout << "Source: " << source << std::endl;
    std::cout << "Auxiliary: " << auxiliary << std::endl;
    std::cout << "Destination: " << destination << std::endl;

    hanoi_tower(n, source, auxiliary, destination, "Source", "Auxiliary", "Destination");

    std::cout << "Final state:" << std::endl;
    std::cout << "Source: " << source << std::endl;
    std::cout << "Auxiliary: " << auxiliary << std::endl;
    std::cout << "Destination: " << destination << std::endl;
}

