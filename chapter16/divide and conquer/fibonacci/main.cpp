#include <iostream>

using namespace std;

int fibonacci(const int& n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cin >> n;

    cout << fibonacci(n);

    return 0;
}