//
// Created by David Owen A. Santiago on 16/09/2025.
//
#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

// Linear search function template
template <typename T>
bool arrayLinearSearch(const T data[], int size, T item) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == item) {
            std::cout << "Searching is successful.\nFound at index: " << i << "\n";
            return true;
        }
    }
    std::cout << "Searching is not successful.\n";
    return false;
}


// Added for linked list
template <typename T>
bool linkedLinearSearch(Node<T> *head, T item ) {
    int index = 0;
    Node<T> *temp = head;
    while (temp != nullptr) {
        if (temp->data == item) {
            std::cout << "Searching is successful.\nFound at node: " << index << "\n";
            return true;
        }
        temp = temp->next;
        ++index;
    }

    std::cout << "Searching is not successful.\n";
    return false;
}

template <typename T>
bool arrayBinarySearch(const T arr[], int size, T item) {
    int low = 0;
    int up = size - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        if (arr[mid] == item) {
            std::cout << "Search element is found at index: " << mid << "\n";
            return true;
        } else if (item < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found.\n";
    return false;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end) {
    if (start == nullptr) return nullptr;
    Node<T>* slow = start;
    Node<T>* fast = start;
    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template <typename T>
Node<T>* linkedBinarySearch(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* end = nullptr;

    while (start != end) {
        Node<T>* mid = getMiddle(start, end);

        if (mid == nullptr) return nullptr;

        if (mid->data == key) {
            std::cout << "Search successful. Found: " << mid->data << "\n";
            return mid;
        } else if (key < mid->data) {
            end = mid;
        } else {
            start = mid->next;
        }
    }

    std::cout << "Search unsuccessful. Element not found.\n";
    return nullptr;
}


template <typename T>
int arrayLinearSearchComparisons(const T data[], int size, T item) {
    int comparisons = 0;
    for (int i = 0; i < size; ++i) {
        comparisons++;
        if (data[i] == item) break;
    }
    return comparisons;
}

template <typename T>
int countOccurrencesArray(const T data[], int size, T item) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (data[i] == item) count++;
    return count;
}

template <typename T>
int linkedLinearSearchComparisons(Node<T>* head, T item) {
    int comparisons = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        comparisons++;
        if (temp->data == item) break;
        temp = temp->next;
    }
    return comparisons;
}

template <typename T>
int countOccurrencesLinkedList(Node<T>* head, T item) {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        if (temp->data == item) count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
int recursiveBinarySearch(const T arr[], T low, T up, T key) {
    if (low > up) return -1;

    int mid = (low + up) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return recursiveBinarySearch(arr, low, mid - 1, key);

    else
        return recursiveBinarySearch(arr, mid + 1, up, key);
}




#endif // SEARCHING_H

