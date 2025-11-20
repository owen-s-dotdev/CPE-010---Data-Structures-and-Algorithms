// #include <iostream>
// #include <cstdlib>
// #include "sorting.h"
//
// const int maxSize = 100;
//
// void line() {
//     std::cout << "---------------------------------------------------------\n";
// }
// void randomNumberArray(int arr[], size_t arrSize) {
//     for (int i = 0; i < maxSize; i++) {
//         arr[i] = rand() % 100;
//     }
// }
// int main() {
//
//     int data[maxSize];
//
//     std::cout << "Array of numbers from 0-100: \n";
//     randomNumberArray(data, maxSize);
//     printArray(data, maxSize);
//
//     line();
//
//     // bubbleSort(data, maxSize);
//     // printArray(data, maxSize);
//
//     //selectionSort(data, maxSize);
//     //printArray(data, maxSize);
//
//     insertionSort(data, maxSize);
//     printArray(data, maxSize);
//
//     return 0;
// }