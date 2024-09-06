#include "tree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree(int capacity, T defaultValue)
    : capacity(capacity), size(0), defaultValue(defaultValue) {
    array = new T[capacity];
    for (int i = 0; i < capacity; ++i) {
        array[i] = defaultValue;
    }
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete[] array;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
bool BinarySearchTree<T>::isFull() const {
    return size == capacity;
}

template<typename T>
void BinarySearchTree<T>::expandArray() {
    int newCapacity = capacity * 2;
    T* newArray = new T[newCapacity];
    for (int i = 0; i < newCapacity; ++i) {
        newArray[i] = i < capacity ? array[i] : defaultValue;
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

template<typename T>
void BinarySearchTree<T>::insert(const T& key) {
    if (isFull()) {
        expandArray();
    }

    int index = 0; // Bắt đầu từ gốc
    while (array[index] != defaultValue) {
        if (key < array[index]) {
            index = getLeftChildIndex(index);
        } else if (key > array[index]) {
            index = getRightChildIndex(index);
        } else {
            throw std::runtime_error("Key already exists in the tree.");
        }
    }
    array[index] = key;
    ++size;
}

template<typename T>
int BinarySearchTree<T>::search(const T& key) const {
    int index = 0;
    while (index < capacity && array[index] != defaultValue) {
        if (key == array[index]) {
            return index;
        } else if (key < array[index]) {
            index = getLeftChildIndex(index);
        } else {
            index = getRightChildIndex(index);
        }
    }
    return -1; // Không tìm thấy
}

template<typename T>
void BinarySearchTree<T>::remove(const T& key) {
    int index = search(key);
    if (index == -1) {
        throw std::runtime_error("Key not found in the tree.");
    }

    --size;
}

template<typename T>
void BinarySearchTree<T>::traverseInOrder(int index) const {
    if (index >= capacity || array[index] == defaultValue) return;

    traverseInOrder(getLeftChildIndex(index));
    std::cout << array[index] << " ";
    traverseInOrder(getRightChildIndex(index));
}

template<typename T>
int BinarySearchTree<T>::height(int index = 0) const {
    if (index >= capacity || array[index] == defaultValue) return -1;
    return std::max(height(getLeftChildIndex(index)), height(getRightChildIndex(index))) + 1;
}

template<typename T>
T BinarySearchTree<T>::getMin() const {
    if (isEmpty()) {
        throw std::runtime_error("The tree is empty.");
    }
    int index = 0;
    while (getLeftChildIndex(index) < capacity && array[getLeftChildIndex(index)] != defaultValue) {
        index = getLeftChildIndex(index);
    }
    return array[index];
}

template<typename T>
T BinarySearchTree<T>::getMax() const {
    if (isEmpty()) {
        throw std::runtime_error("The tree is empty.");
    }
    int index = 0;
    while (getRightChildIndex(index) < capacity && array[getRightChildIndex(index)] != defaultValue) {
        index = getRightChildIndex(index);
    }
    return array[index];
}

template<typename T>
int BinarySearchTree<T>::getLeftChildIndex(int index) const {
    return 2 * index + 1;
}

template<typename T>
int BinarySearchTree<T>::getRightChildIndex(int index) const {
    return 2 * index + 2;
}

template<typename T>
int BinarySearchTree<T>::getParentIndex(int index) const {
    return (index - 1) / 2;
}