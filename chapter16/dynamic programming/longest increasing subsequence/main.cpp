#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n^2)
template<typename T>
int LIS(const vector<T>& subsequence) {
    vector<T> L(subsequence.size(), 1);

    for (int i = 0; i < subsequence.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (subsequence[i] > subsequence[j]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    return *max_element(L.begin(), L.end());
}

int main() {
    int lenght;

    cin >> lenght;

    vector<int> subsequence(lenght);

    for (int i = 0; i < lenght; i++) {
        cin >> subsequence[i];
    }

    cout << LIS(subsequence);
    return 0;
}