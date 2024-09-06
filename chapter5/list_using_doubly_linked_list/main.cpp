#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List<int> list;

    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}