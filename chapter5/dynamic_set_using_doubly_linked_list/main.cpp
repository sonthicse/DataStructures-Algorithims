#include <iostream>
#include "set.h"

int main() {
    // Kiểm tra List
    std::cout << "Kiểm tra List:\n";
    List<int> list;
    
    // Thêm phần tử
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.insert(++list.begin(), 5);
    
    // In danh sách
    std::cout << "Danh sách sau khi thêm phần tử: ";
    for (const auto& item : list) {
        std::cout << item << " ";
    }
    std::cout << "\n";
    
    // Xóa phần tử
    list.pop_front();
    list.pop_back();
    list.erase(++list.begin());
    
    // In danh sách sau khi xóa
    std::cout << "Danh sách sau khi xóa phần tử: ";
    for (const auto& item : list) {
        std::cout << item << " ";
    }
    std::cout << "\n";
    
    // Kiểm tra Set
    std::cout << "\nKiểm tra Set:\n";
    Set<int> set;
    
    // Thêm phần tử
    set.append(1);
    set.append(2);
    set.append(3);
    set.append(2); // Phần tử trùng lặp, sẽ không được thêm vào
    
    // In set
    std::cout << "Set sau khi thêm phần tử: ";
    for (const auto& item : set) {
        std::cout << item << " ";
    }
    std::cout << "\n";
    
    // Kiểm tra tìm kiếm
    std::cout << "Tìm kiếm phần tử 2: " << (set.search(2));

}