#ifndef RB_TREE_H
#define RB_TREE_H

#include <iostream>

enum Color { RED, BLACK };

template<typename T>
struct Node {
    T data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

template<typename T>
class RedBlackTree {
private:
    Node<T>* root;

    // Helper functions
    void leftRotate(Node<T>* x);
    void rightRotate(Node<T>* x);
    void insertFixup(Node<T>* z);
    void deleteFixup(Node<T>* x);
    void transplant(Node<T>* u, Node<T>* v);
    Node<T>* minimum(Node<T>* node);
    void inorderTraversal(Node<T>* node);

public:
    RedBlackTree() : root(nullptr) {}
    void insert(T data);
    void remove(T data);
    bool search(T data);
    void printInorder();
};

#include "rb_tree.cpp"

#endif // RB_TREE_H