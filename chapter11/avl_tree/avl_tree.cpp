#include "avl_tree.h"

template<typename T>
Node<T>* AVLTree<T>::rightRotage(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* Tree2 = x->right;

    x->right = y;
    y->left = Tree2;

    updateHeight(x);
    updateHeight(y);

    return x;
}

template<typename T>
Node<T>* AVLTree<T>::leftRotage(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* Tree2 = y->left;
    
    y->left = x;
    x->right = Tree2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

template<typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, const T& value) {
    if (!node) return new Node<T>(value);

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }

    updateHeight(node);

    int balance = balanceFactor(node);

    if (balance > 1 && value < node->left->data) {
        return rightRotage(node);
    }

    if (balance < -1 && value > node->right->data) {
        return leftRotage(node);
    }

    if (balance > 1 && value > node->left->data) {
        node->left = leftRotage(node->left);
        return rightRotage(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rightRotage(node->right);
        return leftRotage(node);
    }

    return node;
}

template<typename T>
Node<T>* AVLTree<T>::findMin(Node<T>* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left || !node->right) {
            Node<T>* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (!node) return nullptr;

    updateHeight(node);

    int balance = balanceFactor(node);

    if (balance > 1 && value < node->left->data) {
        return rightRotage(node);
    }

    if (balance < -1 && value > node->right->data) {
        return leftRotage(node);
    }

    if (balance > 1 && value > node->left->data) {
        node->left = leftRotage(node->left);
        return rightRotage(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rightRotage(node->right);
        return leftRotage(node);
    }

    return node;
}

template<typename T>
void AVLTree<T>::inOrder(const Node<T>* node) const {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}

template<typename T>
void AVLTree<T>::deleteTree(Node<T>* node) {
    if (node) {
        deleteTree(node->right);
        deleteTree(node->left);
        delete node;
    }
}

template<typename T>
bool AVLTree<T>::search(const Node<T>* node, const T& value) const {
    if (node) {
        if (node->data == value) return true;

        if (node->data > value) return search(node->left, value);

        if (node->data < value) return search(node->right, value);
    }
    return false;
}