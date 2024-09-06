#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
    Linked_List<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << list[i] << " ";
    }
    cout << "successfully\n";
}