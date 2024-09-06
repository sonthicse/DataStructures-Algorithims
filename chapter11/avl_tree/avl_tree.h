#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    int height;

    Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

template<typename T>
class AVLTree {
private:
    Node<T>* root;

    int height(const Node<T>* node) { return node ? node->height : 0; }

    int balanceFactor(const Node<T>* node) { return height(node->left) - height(node->right); }

    void updateHeight(Node<T>* node) { node->height = 1 + std::max(height(node->left), height(node->right)); }

    Node<T>* rightRotage(Node<T>* y);
    Node<T>* leftRotage(Node<T>* x);
    Node<T>* insert(Node<T>* node, const T& value);
    Node<T>* remove(Node<T>* node, const T& value);
    Node<T>* findMin(Node<T>* node);
    void inOrder(const Node<T>* node) const;
    bool search(const Node<T>* node, const T& value) const;
    void deleteTree(Node<T>* node);

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() { deleteTree(root); }

    void insert(const T& value) { root = insert(root, value); }

    void remove(const T& value) { root = remove(root, value);}

    bool search(const T& value) const { return search(root, value); }

    void inOrder() const { inOrder(root); }
};

#include "avl_tree.cpp"

#endif