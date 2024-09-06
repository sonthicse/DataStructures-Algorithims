#ifndef BINARY_SEARCH_TREE_ARRAY_H
#define BINARY_SEARCH_TREE_ARRAY_H

#include <iostream>
#include <stdexcept>

template<typename T>
class BinarySearchTree {
private:
    T* array;           // Mảng động để lưu trữ các giá trị của cây.
    int capacity;       // Sức chứa tối đa của mảng.
    int size;           // Số lượng phần tử hiện tại trong cây.
    T defaultValue;     // Giá trị mặc định để nhận biết các vị trí chưa bị chiếm dụng.

    // Các phương thức riêng tư
    int getLeftChildIndex(int index) const;
    int getRightChildIndex(int index) const;
    int getParentIndex(int index) const;
    void expandArray(); // Mở rộng mảng khi cần thiết

public:
    BinarySearchTree(int capacity, T defaultValue);
    ~BinarySearchTree();

    bool isEmpty() const;
    bool isFull() const;
    void insert(const T& key);
    int search(const T& key) const;
    void remove(const T& key);
    void traverseInOrder(int index = 0) const;
    T getMin() const;
    T getMax() const;
    int height(int index = 0) const;
};

#include "tree.cpp"

#endif
