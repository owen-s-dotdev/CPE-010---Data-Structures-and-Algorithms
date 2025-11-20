//
// Created by David Owen A. Santiago on 16/09/2025.
//
#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>

// Linear search function template
template <typename T>
bool arrayLinearSearch(const T data[], int size, T item) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == item) {
            std::cout << "Searching is successful. Found at index: " << i << "\n";
            return true;
        }
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

