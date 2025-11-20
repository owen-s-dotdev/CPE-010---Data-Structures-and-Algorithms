//
// Created by oms2v on 04/10/2025.
//

#ifndef TREES_H
#define TREES_H
#include <iostream>
#include <cstdlib>
#include <vector>


// General Tree
template<typename T>
class generalTree {
private:
    T key;
    std::vector<generalTree<T>*> children;

public:
    generalTree(T val) {
        key = val;
    }

    void addChild(T val) {
        generalTree<T>* child = new generalTree<T>(val);
        children.push_back(child);
    }

    void addChild(generalTree<T>* child) {
        children.push_back(child);
    }

    T getKey() {
        return key;
    }

    std::vector<generalTree<T>*>& getChildren() {
        return children;
    }

    void printTree(int depth = 0) {
        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << key << "\n";
        for (generalTree<T>* child : children) {
            child->printTree(depth + 1);
        }
    }

    int getHeight() {
        if (children.empty()) return 0;

        int maxHeight = 0;
        for (generalTree<T>* child : children) {
            int childHeight = child->getHeight();
            if (childHeight > maxHeight)
                maxHeight = childHeight;
        }
        return 1 + maxHeight;
    }
    // height
    int getNodeHeight(const T& target) {
        if (key == target) return getHeight();

        for (generalTree<T>* child : children) {
            int height = child->getNodeHeight(target);
            if (height != -1) return height;
        }

        return -1; // Target not found
    }

    // get depth
    int getDepth(const T& target, int currentDepth = 0) {
        if (key == target) return currentDepth;

        for (generalTree<T>* child : children) {
            int depth = child->getDepth(target, currentDepth + 1);
            if (depth != -1) return depth;
        }

        return -1; // Not found
    }

    void printHeightDepth(const T& target) {
        int depth = getDepth(target);
        int height = getNodeHeight(target);
        if (depth == -1 || height == -1)
            std::cout << "Node " << target << " not found.\n";
        else
            std::cout << "Node " << target << ": Depth = " << depth << ", Height = " << height << "\n";
    }

    void printAllHeightDepth(int currentDepth = 0) {
        int height = getNodeHeight(key); // Height of this node
        std::cout << "Node " << key << ": Depth = " << currentDepth << ", Height = " << height << "\n";

        for (generalTree<T>* child : children) {
            child->printAllHeightDepth(currentDepth + 1);
        }
    }

    void traversePreOrder() {
        std::cout << key << " ";
        for (generalTree<T>* child : children) {
            child->traversePreOrder();
        }
    }

    void traversePostOrder() {
        for (generalTree<T>* child : children) {
            child->traversePostOrder();
        }
        std::cout << key << " ";
    }

    void traverseInOrder() {
        int n = children.size();
        int mid = n / 2;

        for (int i = 0; i < mid; ++i) {
            children[i]->traverseInOrder();
        }

        std::cout << key << " ";

        for (int i = mid; i < n; ++i) {
            children[i]->traverseInOrder();
        }
    }

    void findData(const std::string& choice, const T& target) {
        if (choice == "pre") {
            findPreOrder(target);
        } else if (choice == "post") {
            findPostOrder(target);
        } else if (choice == "in") {
            findInOrder(target);
        } else {
            std::cout << "Invalid traversal choice.\n";
        }
    }

    void findPreOrder(const T& target) {
        if (key == target) {
            std::cout << key << " was found!\n";
            return;
        }
        for (generalTree<T>* child : children) {
            child->findPreOrder(target);
        }
    }

    void findPostOrder(const T& target) {
        for (generalTree<T>* child : children) {
            child->findPostOrder(target);
        }
        if (key == target) {
            std::cout << key << " was found!\n";
        }
    }

    void findInOrder(const T& target) {
        int n = children.size();
        int mid = n / 2;

        for (int i = 0; i < mid; ++i) {
            children[i]->findInOrder(target);
        }

        if (key == target) {
            std::cout << key << " was found!\n";
            return;
        }

        for (int i = mid; i < n; ++i) {
            children[i]->findInOrder(target);
        }
    }

    ~generalTree() {
        for (generalTree<T>* child : children) {
            delete child;
        }
    }
};

// Binary Tree
template<typename T>
class BinaryTree {
private:
    T key;
    BinaryTree* leftChild;
    BinaryTree* rightChild;

public:

    BinaryTree(T rootObj) {
        this->key = rootObj;
        this->leftChild = nullptr;
        this->rightChild = nullptr; // "this" keyword is a pointer exclusive inside the class
    }

    void insertLeft(T newNode) {
        if (this->leftChild == nullptr) {
            this->leftChild = new BinaryTree(newNode);
        } else {
            BinaryTree* t = new BinaryTree(newNode);
            t->leftChild = this->leftChild;
            this->leftChild = t;
        }
    }

    void insertRight(T newNode) {
        if (this->rightChild == nullptr) {
            this->rightChild = new BinaryTree(newNode);
        } else {
            BinaryTree* t = new BinaryTree(newNode);
            t->rightChild = this->rightChild;
            this->rightChild = t;
        }
    }

    BinaryTree* getLeftChild() {
        return this->leftChild;
    }

    BinaryTree* getRightChild() {
        return this->rightChild;
    }

    char getRootVal() {
        return this->key;
    }

    void setRootVal(char obj) {
        this->key = obj;
    }

    ~BinaryTree() {
        delete leftChild;
        delete rightChild;
    }
    void visitBT(BinaryTree* node) {
        std::cout << node->getRootVal() << " ";
    }

    void preOrderBT(BinaryTree* node) {
        if (!node) return;
        visit(node);
        preOrder(node->getLeftChild());
        preOrder(node->getRightChild());
    }

    void inOrderBT(BinaryTree* node) {
        if (!node) return;
        inOrder(node->getLeftChild());
        visit(node);
        inOrder(node->getRightChild());
    }

    void postOrderBT(BinaryTree* node) {
        if (!node) return;
        postOrder(node->getLeftChild());
        postOrder(node->getRightChild());
        visit(node);
    }
};

//Binary Search Tree
template<typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree* leftChild;
    BinarySearchTree* rightChild;

public:
    BinarySearchTree(T val) {
        key = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    void insert(T val) {
        if (val < key) {
            if (leftChild == nullptr)
                leftChild = new BinarySearchTree(val);
            else
                leftChild->insert(val);
        } else if (val > key) {
            if (rightChild == nullptr)
                rightChild = new BinarySearchTree(val);
            else
                rightChild->insert(val);
        } else {
            std::cout << "Duplicate value. Left value must be less than the right value.\n";
        }
    }

    void inOrderSearch(T data) {
        if (leftChild) leftChild->inOrderSearch(data);
        if (key == data)
            std::cout << "Found " << data << " in in-order traversal.\n";
        if (rightChild) rightChild->inOrderSearch(data);
    }

    void preOrderSearch(T data) {
        if (key == data)
            std::cout << "Found " << data << " in pre-order traversal.\n";
        if (leftChild) leftChild->preOrderSearch(data);
        if (rightChild) rightChild->preOrderSearch(data);
    }

    void postOrderSearch(T data) {
        if (leftChild) leftChild->postOrderSearch(data);
        if (rightChild) rightChild->postOrderSearch(data);
        if (key == data)
            std::cout << "Found " << data << " in post-order traversal.\n";
    }

    void traversePreOrder() {
        std::cout << key << " ";
        if (leftChild) leftChild->traversePreOrder();
        if (rightChild) rightChild->traversePreOrder();
    }

    void traverseInOrder() {
        if (leftChild) leftChild->traverseInOrder();
        std::cout << key << " ";
        if (rightChild) rightChild->traverseInOrder();
    }

    void traversePostOrder() {
        if (leftChild) leftChild->traversePostOrder();
        if (rightChild) rightChild->traversePostOrder();
        std::cout << key << " ";
    }

    ~BinarySearchTree() {
        delete leftChild;
        delete rightChild;
    }
};

#endif //TREES_H
