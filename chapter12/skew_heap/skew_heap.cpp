#include "skew_heap.h"
#include <stdexcept>

template <typename T>
std::unique_ptr<typename SkewHeap<T>::Node> SkewHeap<T>::merge(std::unique_ptr<Node> a, std::unique_ptr<Node> b) {
    if (!a) return std::move(b);
    if (!b) return std::move(a);

    if (b->value < a->value) {
        std::swap(a, b);
    }

    std::swap(a->left, a->right);
    a->left = merge(std::move(b), std::move(a->left));

    return std::move(a);
}

template <typename T>
void SkewHeap<T>::insert(const T& value) {
    auto new_node = std::make_unique<Node>(value);
    root = merge(std::move(root), std::move(new_node));
}

template <typename T>
bool SkewHeap<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
T SkewHeap<T>::findMin() const {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return root->value;
}

template <typename T>
void SkewHeap<T>::deleteMin() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    root = merge(std::move(root->left), std::move(root->right));
}

template <typename T>
void SkewHeap<T>::clear() {
    root = nullptr;
}

// Explicit template instantiation for common types
template class SkewHeap<int>;
template class SkewHeap<double>;
template class SkewHeap<float>;