#include "splay_tree.h"

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::splay(Node* root, const T& key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data) {
        if (root->left == nullptr) return root;
        if (key < root->left->data) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->data) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }
        return (root->left == nullptr) ? root : rightRotate(root);
    } else {
        if (root->right == nullptr) return root;
        if (key > root->right->data) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->data) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::insert(Node* root, const T& key) {
    if (root == nullptr)
        return new Node(key);

    root = splay(root, key);

    if (root->data == key)
        return root;

    Node* newNode = new Node(key);
    if (key < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::remove(Node* root, const T& key) {
    if (root == nullptr)
        return nullptr;

    root = splay(root, key);

    if (key != root->data)
        return root;

    Node* temp;
    if (root->left == nullptr) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    delete temp;
    return root;
}

template <typename T>
void SplayTree<T>::inorderTraversal(Node* root) const {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

template <typename T>
void SplayTree<T>::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <typename T>
SplayTree<T>::~SplayTree() {
    deleteTree(root);
}

template <typename T>
void SplayTree<T>::insert(const T& key) {
    root = insert(root, key);
}

template <typename T>
void SplayTree<T>::remove(const T& key) {
    root = remove(root, key);
}

template <typename T>
bool SplayTree<T>::search(const T& key) {
    root = splay(root, key);
    return (root != nullptr && root->data == key);
}

template <typename T>
void SplayTree<T>::printInorder() const {
    inorderTraversal(root);
    std::cout << std::endl;
}