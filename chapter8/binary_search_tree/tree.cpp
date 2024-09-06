#include "tree.h"
#include <iostream>

template<typename T>
Tree<T>::Tree(const Tree& other) : root(nullptr) {
    if (other.root != nullptr) {
        root = new Node(other.root->getData());
        copyHelper(root, other.root);
    }
}

template<typename T>
void Tree<T>::copy(Node* newNode, const Node* originalNode) {
    if (originalNode->getLeft() != nullptr) {
        newNode->setLeft(new Node(originalNode->getLeft()->getData()));
        newNode->getLeft()->setParent(newNode);
        copy(newNode->getLeft(), originalNode->getLeft());
    }
    if (originalNode->getRight() != nullptr) {
        newNode->setRight(new Node(originalNode->getRight()->getData()));
        newNode->getRight()->setParent(newNode);
        copy(newNode->getRight(), originalNode->getRight());
    }
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree& other) {
    if (this != &other) {
        makeEmpty(root);
        root = nullptr;
        if (other.root != nullptr) {
            root = new Node(other.root->getData());
            copyHelper(root, other.root);
        }
    }
    return *this;
}

template<typename T>
void Tree<T>::makeEmpty(Node* node) {

    if (node->getLeft() == nullptr && node->getRight()) {
        delete node;
        return;
    }

    makeEmpty(node->getLeft());
    makeEmpty(node->getRight());
}

template<typename T>
Tree<T>::~Tree() {
    makeEmpty(root);
}

template<typename T>
typename Tree<T>::Node* Tree<T>::min(const Node* node) const {
    Node* current = root;
    
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }

    return current;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::max(const Node* node) const {
    Node* current = root;

    while (current->getRight() != nullptr) {
        current = current->getRight();
    }

    return current;
}

template<typename T>
void Tree<T>::inorder(const Node* node) const {

    if (node != nullptr) {
        inorder(node->getLeft());
        std::cout << node->getData() << " ";
        inorder(node->getRight());
    }
}

template<typename T>
void Tree<T>::preorder(const Node* node) const {

    if (node != nullptr) {
        std::cout << node->getData() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}

template<typename T>
void Tree<T>::postorder(const Node* node) const {

    if (node != nullptr) {
        postorder(node->getLeft());
        postorder(node->getRight());
        std::cout << node->getData() << " ";
    }
}

template<typename T>
void Tree<T>::insert(const T& value) {
    Node* newNode = new Node(value);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->getData()) {
            current = current->getLeft();
        } else if (value > current->getData()) {
            current = current->getRight();
        } else {
            delete newNode;
            return;
        }
    }

    newNode->setParent(parent);

    if (value < parent->getData()) {
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }
}

template<typename T>
void Tree<T>::remove(const T& value) {
    Node* nodeToRemove = find(value);
    if (nodeToRemove == nullptr) return;

    if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() == nullptr) {
        // Case 1: Node is a leaf
        if (nodeToRemove == root) {
            root = nullptr;
        } else {
            Node* parent = nodeToRemove->getParent();
            if (parent->getLeft() == nodeToRemove) {
                parent->setLeft(nullptr);
            } else {
                parent->setRight(nullptr);
            }
        }
        delete nodeToRemove;
    } else if (nodeToRemove->getLeft() == nullptr || nodeToRemove->getRight() == nullptr) {
        // Case 2: Node has one child
        Node* child = (nodeToRemove->getLeft() != nullptr) ? nodeToRemove->getLeft() : nodeToRemove->getRight();
        if (nodeToRemove == root) {
            root = child;
            child->setParent(nullptr);
        } else {
            Node* parent = nodeToRemove->getParent();
            if (parent->getLeft() == nodeToRemove) {
                parent->setLeft(child);
            } else {
                parent->setRight(child);
            }
            child->setParent(parent);
        }
        delete nodeToRemove;
    } else {
        // Case 3: Node has two children
        Node* successor = min(nodeToRemove->getRight());
        T successorData = successor->getData();
        remove(successorData);
        nodeToRemove->setData(successorData);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::find(const T& value) const {
    Node* current = root;

    while (current != nullptr) {
        if (value < current->getData()) {
            current = current->getLeft();
        } else if (value > current->getData()) {
            current = current->getRight();
        } else {
            return current;
        }
    }

    return nullptr;
}

template<typename T>
bool Tree<T>::search(const T& value) const {
    Node* current = root;

    while (current != nullptr) {
        if (value < current->getData()) {
            current = current->getLeft();
        } else if (value > current->getData()) {
            current = current->getRight();
        } else {
            return true;
        }
    }

    return false;
}

template<typename T>
T& Tree<T>::min() const {
    return min(root)->getData;
}

template<typename T>
T& Tree<T>::max() const {
    return max(root)->getData();
}

template<typename T>
void Tree<T>::inorder() const {
    inorder(root);
}

template<typename T>
void Tree<T>::preorder() const {
    preorder(root);
}

template<typename T>
void Tree<T>::postorder() const {
    postorder(root);
}