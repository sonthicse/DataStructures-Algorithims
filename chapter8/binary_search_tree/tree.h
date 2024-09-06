#ifndef TREE_H
#define TREE_H

template<typename T>
class Tree {
private:
    class Node {
    private:
        T data;
        Node* parent;
        Node* left;
        Node* right;
    
    public:
        Node(const T& value) : data(value), parent(nullptr), left(nullptr), right(nullptr) {}

        T getData() const { return data; }

        Node* getParent() const { return parent; }

        Node* getLeft() const { return left; }

        Node* getRight() const { return right; }

        void setData(const T& value) { data = value; }

        void setParent(Node* node) { parent = node; }

        void setLeft(Node* node) { left = node; }

        void setRight(Node* node) { right = node; }
    };

    Node* root;

    void copy(Node* newNode, const Node* originalNode);

    void makeEmpty(Node* node);

    Node* min(const Node* node) const;

    Node* max(const Node* node) const;

    Node* find(const T& value) const;

    void inorder(const Node* node) const;

    void preorder(const Node* node) const;

    void postorder(const Node* node) const;
    
public:
    Tree() : root(nullptr) {}

    Tree(const Tree& other);

    ~Tree();

    Tree& operator=(const Tree& other);

    bool empty() const { return root == nullptr; }

    void insert(const T& value);

    void remove(const T& value);

    bool search(const T& value) const;

    T& min() const;

    T& max() const;

    void inorder() const;

    void preorder() const;

    void postorder() const;
};

#include "tree.cpp"

#endif