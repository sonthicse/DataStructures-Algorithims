#include <iostream>

using namespace std;

// Backtracking

// In ra các hoán vị từ 1 đến 4
int array[4];
bool check[4];
int stt = 1;

void backtrack(int step) {
    if (step > 4) {
        cout << stt << ". "; stt++;
        for (int i = 0; i < 4; i++ ) {
            cout << array[i] << " ";
        }

        cout << endl;

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (check[i] == 0) {
            array[i] = step;
            check[i] = 1;
            backtrack(step + 1);
            check[i] = 0;
        }
    }
}

int main() {
    backtrack(1);

    return 0;
}