#include <iostream>

using namespace std;

template<typename T>
void MaxMin(const T* array, const int& i, const int& j, T& max, T& min) {
    if (i == j) {
        max = min = array[i];
    } else if (i == j - 1) {
        if (array[i] < array[j]) {
            max = array[j];
            min = array[j];
        } else {
            max = array[i];
            min = array[j];
        }
    } else {
        int mid = (i + j)/2;
        T max1, min1, max2, min2;
        MaxMin(array, i, mid, max1, min1);
        MaxMin(array, mid + 1, j, max2, min2);
        if (max1 < max2) {
            max = max2;
        } else {
            max = max1;
        }
        if (min1 < min2) {
            min = min1;
        } else {
            min = min2;
        }
    }
}

int main() {
    int n, max, min;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MaxMin(arr, 0, n - 1, max, min);

    cout << max << ", " << min;

    return 0;
}