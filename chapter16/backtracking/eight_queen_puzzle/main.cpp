#include <iostream>

using namespace std;

void EightQueenPuzzle(int result[], int row) {
    if (row == 8) {
        for (int i = 0; i < 8; i++) {
            cout << result[i] << " ";
        }

        cout << endl;
        return;
    } else {
        // Backtrack
        for (int i = 0; i < 8; i++ ) {
            bool check = true;
            // Kiem tra xem dat quan hau duoc hay khong
            for (int j = 0; j < 8; j++) {
                if (i == result[j] || abs(i - result[j]) == abs(row - j)) {
                    check = false;
                    break;
                }
            }

            // Neu dat duoc quan hau
            if (check) {
                result[row] = i;
                EightQueenPuzzle(result, row + 1);
            }
        }
    }
}

int main() {
    int result[8];

    EightQueenPuzzle(result, 0);

    return 0;
}