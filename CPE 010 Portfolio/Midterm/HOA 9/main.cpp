#include <iostream>
#include "trees.h"

void line() {
    std::cout <<"------------------------\n";
}

int main() {
    // Array of values to be inserted
    int arr[] = {3, 9, 18, 0, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initializing binary search tree with 2 as the root
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(2);
    // Loop for simplified insertion
    for (int i = 0; i < n; i++) {
        bst->insert(arr[i]);
    }

    std::cout << "In-order:\n";
    bst->traverseInOrder(); std::cout << '\n';
    line();

    std::cout << "Pre-order:\n";
    bst->traversePreOrder(); std::cout << '\n';
    line();

    std::cout << "Post-order:\n";
    bst->traversePostOrder(); std::cout << '\n';
    line();

    delete bst;

    return 0;

}
