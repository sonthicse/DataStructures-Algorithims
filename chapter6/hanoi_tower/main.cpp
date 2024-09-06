#include <iostream>
#include "hanoi_tower.cpp"

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of disks must be positive." << std::endl;
        return 1;
    }

    solve_hanoi_tower<int>(n);

    return 0;
}