#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include <memory>
#include <iostream>

template <typename T>
class SkewHeap {
private:
    struct Node {
        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    std::unique_ptr<Node> merge(std::unique_ptr<Node> a, std::unique_ptr<Node> b);

    void inOrderTraversal(const std::unique_ptr<Node> node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    SkewHeap() : root(nullptr) {}

    void insert(const T& value);
    bool isEmpty() const;
    T findMin() const;
    void deleteMin();
    void clear();

    void printInOrder() const {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

#include "skew_heap.cpp"

#endif // SKEW_HEAP_H