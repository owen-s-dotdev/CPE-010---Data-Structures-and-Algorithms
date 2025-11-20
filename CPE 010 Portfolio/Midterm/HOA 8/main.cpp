#include <iostream>
#include "sorting_pt2.h"

const int maxSize = 100;

void line() {
    std::cout << "-----------------------------------------------------------------\n";
}

int main() {

    resetCounters();

    int original[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int size = sizeof(original) / sizeof(original[0]);

    // Copying array for testing
    int arrShell[maxSize], arrMerge[maxSize], arrQuick[maxSize], arrQuickShell[maxSize];
    for (int i = 0; i < size; i++) {
        arrShell[i] = original[i];
        arrMerge[i] = original[i];
        arrQuick[i] = original[i];
        arrQuickShell[i] = original[i];
    }

    std::cout << "Original Array:\n";
    printArray(original, size);
    line();

    // Shell Sort
    std::cout << "Shell Sort:\n";
    resetCounters();
    shellSort(arrShell, size);
    printArray(arrShell, size);
    printCounters();
    line();

    // Merge Sort
    std::cout << "Merge Sort:\n";
    resetCounters();
    merge_sort(arrMerge, 0, size - 1);
    printArray(arrMerge, size);
    printCounters();
    line();

    // Quicksort
    std::cout << "Quicksort:\n";
    resetCounters();
    quicksort(arrQuick, 0, size - 1);
    printArray(arrQuick, size);
    printCounters();
    line();

    // QuickShellSort
    std::cout << "Quick Shell Sort Hybrid: \n";
    resetCounters();
    hybridQuickShellSort(arrQuickShell, 0, size - 1);
    printArray(arrQuickShell, size);
    printCounters();
    line();

    return 0;
}


