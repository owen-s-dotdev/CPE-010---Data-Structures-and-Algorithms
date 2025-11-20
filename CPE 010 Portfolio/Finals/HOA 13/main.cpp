//
// Created by David Owen A. Santiago on 03/11/2025.
//

#include <iostream>
#include <thread>
#include <vector>
#include "searching.h"

void runBinarySearch(int* arr, int size, int target) {
    arrayBinarySearch<int>(arr, size, target);
}

void runLinearSearch(int* arr, int size, int target) {
    arrayLinearSearch<int>(arr, size, target);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    std::thread t1(runBinarySearch, arr, size, target);
    t1.join();
    std::thread t2(runLinearSearch, arr, size, target);

    t2.join();


    return 0;
}
