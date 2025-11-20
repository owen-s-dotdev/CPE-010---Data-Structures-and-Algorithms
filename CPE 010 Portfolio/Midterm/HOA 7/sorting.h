//
// Created by oms2v on 18/09/2025.
//

#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <cstdlib>

//swapping
template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//printing
template<typename T>
void printArray(T arr[], size_t arrSize) {
    std::cout << "Array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }std::cout << '\n';
}

//bubble
template<typename T>
void bubbleSort(T arr[], size_t arrSize) {
    std::cout << "Bubble Sort: \n";
    // To keep track of the number of swaps
    int swaps = 0;
    // To keep track of comparisons
    int comparisons = 0;
    // Step 1: For i = 0 to N - 1 repeat step 2
    // Traversal Loop
    for (int i = 0; i < arrSize - 1; i++) {
        // Step 2: For j = i + 1 to N - i repeat
        // Comparison loop
        for (int j = i + 1; j < arrSize; j++) {
            // Incrementing comparisons to keep track
            comparisons++;
            // Reverse arrow for descending order
            if (arr[i] > arr[j]) {
                swap(arr[j], arr[i]);
                // Increments only if swapped
                swaps++;
            }
        }
    }
    std::cout << "Swaps: " << swaps << '\n';
    std::cout << "Comparisons: " << comparisons << '\n';
}

//selection
template<typename T>
int routineSmallest(T A[], int K, const int arrSize, int &comparisons) {
    int position, j;
    // Step 1: [initialize] set smallestElem = A[K]
    T smallestElem = A[K];
    // Step 2:  [initialize] set POS = K
    position = K;
    // Step 3: for J = K + 1 to N - 1 repeat
    for (int j = K + 1; j < arrSize; j++) {
        comparisons++;
        if (A[j] < smallestElem) {
            smallestElem = A[j];
            position = j;
        }
    }
    // Step 4: Return pos
    return position;

}
template<typename T>
void selectionSort(T arr[], const int N) {
    int swaps = 0;
    int comparisons = 0;
    int POS;
    std::cout << "Selection Sort: \n";

    // Step 1: Repeat Steps 2 and 3 for K = 1 to N-1
    for (int i = 0; i < N; i++) {
        // Step 2: Call routine smallest(A, K, N, POS, added comparisons to track)
        POS = routineSmallest(arr, i, N, comparisons);
        // Step 3: Swap A[K] with A[POS]
        if (i != POS) {
            swap(arr[i], arr[POS]);
            swaps++;
        }
    }
    std::cout << "Swaps: " << swaps << '\n';
    std::cout << "Comparisons: " << comparisons << '\n';
}

//insertion
template<typename T>
void insertionSort(T arr[], const int N) {
    std::cout << "Insertion Sort: \n";
    int K = 1, J;
    T temp;
    int comparisons = 0;
    int moves = 0;

    // Step 1: Repeat steps 2-5 for K = 1 to N - 1
    while (K < N) {
        // Step 2: set temp = A[K]
        temp = arr[K];
        // Step 3: set J = K - 1 to start comparison on the element before K
        J = K - 1;

        // Step 4: Repeat while temp <= A[J]
        while (J >= 0 && temp < arr[J] ) {
            comparisons++;
            // Set A[J + 1] = A[J]
            arr[J + 1] = arr[J];
            moves++;
            // Set J = J - 1
            J--;
        }
        if (J >= 0) comparisons++; // includes last comparison
        // Step 5: set A[J + 1] = temp
        arr[J + 1] = temp;
        moves++;
        K++;
    }
    std::cout << "Moves: " << moves << '\n';
    std::cout << "Comparisons: " << comparisons << '\n';
}

#endif //SORTING_H
