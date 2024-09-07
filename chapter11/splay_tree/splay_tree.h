#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>

template <typename T>
class SplayTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* splay(Node* root, const T& key);
    Node* leftRotate(Node* x);
    Node* rightRotate(Node* x);
    Node* insert(Node* root, const T& key);
    Node* remove(Node* root, const T& key);
    void inorderTraversal(Node* root) const;
    void deleteTree(Node* node);

public:
    SplayTree() : root(nullptr) {}
    ~SplayTree();

    void insert(const T& key);
    void remove(const T& key);
    bool search(const T& key);
    void printInorder() const;
};

#include "splay_tree.cpp"

#endif // SPLAY_TREE_H