//
// Created by oms2v on 16/09/2025.
//

#ifndef NODES_H
#define NODES_H

template <typename T>
class Node {
    public:
    T data;
    Node<T>* next;

    Node<T> *new_node(T new_data) {
        Node<T> *newNode = new Node<T>();
        newNode->data = new_data;
        newNode->next = nullptr;
        return newNode;
    }

    ~Node() = default;
};


#endif //NODES_H
