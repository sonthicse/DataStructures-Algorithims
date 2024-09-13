/*
    Giả sử ta có chiếc ba lô có thể chứa được một khối lượng w, chúng ta có n loại 
    đồ vật được đánh số i,…, n. Mỗi đồ vật loại i (i = 1,…, n) có khối lượng ai và 
    có giá trị ci. Chúng ta muốn sắp xếp các đồ vật vào ba lô để nhận được ba lô có 
    giá trị lớn nhất có thể được. Giả sử mỗi loại đồ vật có đủ nhiều đề xếp vào ba lô. 
*/

/*
1. Mô tả bài toán:
    - Có một ba lô có thể chứa khối lượng tối đa là w.
    - Có n loại đồ vật, mỗi loại i có:
        + Khối lượng ai
        + Giá trị ci
    - Mục tiêu: Xếp đồ vật vào ba lô sao cho tổng giá trị là lớn nhất có thể.

2. Công thức toán học:
    - Tìm các số nguyên không âm xi (i = 1,...,n) sao cho:
        + Σ(xi * ai) ≤ w (tổng khối lượng không vượt quá w)
        + Σ(xi * ci) đạt giá trị lớn nhất (tổng giá trị là lớn nhất)

3. Phương pháp giải:
    - Sử dụng quy hoạch động, chia bài toán thành các bài toán con nhỏ hơn.
    - Định nghĩa cost(k,v) là giá trị lớn nhất có thể đạt được khi xét k loại đồ vật đầu tiên và ba lô có khối lượng tối đa là v.

4. Công thức quy hoạch động:
    - Trường hợp cơ sở (k = 1):
        cost(1,v) = x1c1, với x1 = v / a1 (số lượng đồ vật loại 1 có thể xếp vào ba lô)

    - Công thức tổng quát:
        cost(k,v) = max[cost(k-1,u) + xkck]
        Trong đó:
        - u = v - xkak (khối lượng còn lại sau khi xếp xk đồ vật loại k)
        - xk = 0, 1, ..., yk với yk = v / ak (số lượng tối đa đồ vật loại k có thể xếp)

5. Cách tính:
    - Sử dụng mảng 2 chiều A[0..n-1][0..w-1] để lưu kết quả của các bài toán con.
    - Tính các giá trị trong mảng A từ trái qua phải, từ trên xuống dưới.
    - A[k-1][v-1] chứa cost(k,v) và số đồ vật loại k cần xếp.

6. Truy vết để tìm nghiệm:
    - Bắt đầu từ A[n-1][w-1] (nghiệm của bài toán gốc).
    - Tìm số đồ vật loại n cần xếp (xn).
    - Tính v = w - xnan (khối lượng còn lại).
    - Tiếp tục với A[n-2][v-1] để tìm xn-1, và cứ thế cho đến x1.

    Thuật toán này có độ phức tạp O(n*w), với n là số loại đồ vật và w là khối lượng tối đa của ba lô. Đây là một cải tiến đáng kể so với phương pháp vét cạn có độ phức tạp O(2^n).

    Thuật toán này hiệu quả vì nó tránh được việc tính toán lặp lại các bài toán con bằng cách lưu trữ kết quả trong mảng A. Điều này giúp giảm đáng kể thời gian tính toán, đặc biệt với các bài toán có số lượng đồ vật lớn.
*/


#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

vector<int> knapsack(int W, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> A(n, vector<int>(W + 1, 0));
    vector<vector<int>> K(n, vector<int>(W + 1, 0));

    // Điền bảng A và K
    for (int i = 0; i < n; i++) {
        for (int w = 1; w <= W; w++) {
            if (i == 0) {
                if (items[i].weight <= w) {
                    A[i][w] = items[i].value * (w / items[i].weight);
                    K[i][w] = w / items[i].weight;
                }
            } else {
                A[i][w] = A[i-1][w];
                K[i][w] = 0;
                for (int k = 1; k * items[i].weight <= w; k++) {
                    int val = A[i-1][w - k * items[i].weight] + k * items[i].value;
                    if (val > A[i][w]) {
                        A[i][w] = val;
                        K[i][w] = k;
                    }
                }
            }
        }
    }

    // Truy vết để tìm số lượng mỗi loại đồ vật
    vector<int> result(n, 0);
    int w = W;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = K[i][w];
        w -= result[i] * items[i].weight;
    }

    return result;
}

int main() {
    int W, n;
    cout << "Nhap trong luong toi da cua ba lo: ";
    cin >> W;
    cout << "Nhap so luong loai do vat: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap trong luong va gia tri cua do vat " << i+1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    vector<int> result = knapsack(W, items);

    cout << "So luong moi loai do vat can xep vao ba lo:\n";
    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        cout << "Do vat " << i+1 << ": " << result[i] << endl;
        totalValue += result[i] * items[i].value;
    }
    cout << "Tong gia tri: " << totalValue << endl;

    return 0;
}