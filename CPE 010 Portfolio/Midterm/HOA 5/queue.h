//Created on 09-09-25
//by David Owen Santiago, CPE21S4

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T new_data) {
        data = new_data;
        next = nullptr;
    }
};

template<typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size = 0;

public:
    Queue() {
        front = rear = nullptr;
        std::cout << "A queue has been created.\n";
    }

    Queue(const Queue<T>& original) {
        front = rear = nullptr;
        size = 0;
        Node<T>* temp = original.front;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
        std::cout << "Queue copied successfully.\n";
    }

    ~Queue() {
        clear();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(T new_data) {
        Node<T>* new_node = new Node<T>(new_data);
        if (isEmpty()) {
            front = rear = new_node;
            std::cout << "Enqueued to an empty queue\n";
            size++;
            return;
        }
        rear->next = new_node;
        rear = new_node;
        std::cout << "Enqueued\n";
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        std::cout << "Successfully dequeued.\n";
        size--;
    }

    void getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Front is: " << front->data << '\n';
    }

    void getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Rear is: " << rear->data << '\n';
    }

    void printQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node<T>* temp = front;
        std::cout << "Current Queue: ";
        while (temp != nullptr) {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    int QueueSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif
