#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Chuyen dia 1 tu cot " << from_rod << " sang cot " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Chuyen dia " << n << " tu cot " << from_rod << " sang cot " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 4; // Số đĩa
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C là tên các cột
    return 0;
}