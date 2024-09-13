#include <iostream>

using namespace std;

int fibonacci(const int& n) {
    if (n == 0)
        return 0;

    if (n == 1 || n == 2) {
        return 1;
    } else {
        int pre = 1;
        int cur = 1;

        for (int i = 3; i <= n; i++) {
            cur += pre;
            pre = cur - pre;
        }

        return cur;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);

    return 0;
}