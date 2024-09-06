#include "tree.h"

int main() {
    try {
        // Tạo một cây tìm kiếm nhị phân với dung lượng 15 và giá trị mặc định là -1
        BinarySearchTree<int> bst(15, -1);

        // Kiểm tra xem cây có rỗng không
        std::cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

        // Chèn các giá trị vào cây
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);

        // Kiểm tra xem cây có rỗng không sau khi chèn
        std::cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

        // Duyệt cây theo thứ tự In-order (LNR)
        std::cout << "In-order traversal of the BST: ";
        bst.traverseInOrder();
        std::cout << std::endl;

        // Tìm kiếm giá trị trong cây
        int searchValue = 40;
        int searchIndex = bst.search(searchValue);
        std::cout << "Search for value " << searchValue << " in the BST: " 
                  << (searchIndex != -1 ? "Found at index " + std::to_string(searchIndex) : "Not Found") << std::endl;

        // Tìm kiếm giá trị không có trong cây
        searchValue = 100;
        searchIndex = bst.search(searchValue);
        std::cout << "Search for value " << searchValue << " in the BST: " 
                  << (searchIndex != -1 ? "Found at index " + std::to_string(searchIndex) : "Not Found") << std::endl;

        // Tìm giá trị nhỏ nhất và lớn nhất trong cây
        std::cout << "Minimum value in the BST: " << bst.getMin() << std::endl;
        std::cout << "Maximum value in the BST: " << bst.getMax() << std::endl;

        // Kiểm tra chiều cao của cây
        std::cout << "Height of the BST: " << bst.height() << std::endl;

        // Xóa một giá trị trong cây
        bst.remove(70);
        std::cout << "In-order traversal after deleting 70: ";
        bst.traverseInOrder();
        std::cout << std::endl;

        // Xóa một giá trị không có trong cây
        try {
            bst.remove(100);
        } catch (const std::runtime_error& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Kiểm tra chiều cao sau khi xóa
        std::cout << "Height of the BST after deletion: " << bst.height() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
