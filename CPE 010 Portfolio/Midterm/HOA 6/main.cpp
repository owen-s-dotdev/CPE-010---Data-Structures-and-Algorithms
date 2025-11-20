#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"

const int max_size = 50;

void line() {
    std::cout << "-------------------------------\n";
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int key = 8;

    int result = recursiveBinarySearch(arr1, 0, size1 - 1 , key);

    if (result == -1) {
        std::cout << key << " not found\n";
    }
    else {
        std::cout << key << " found at index: " << result << '\n';
    }

    return 0;
}

/*
int comparisons = arrayLinearSearchComparisons(arr1, size1, key);
std::cout << "Comparisons done to find " << key <<": "<< comparisons << '\n';

comparisons = linkedLinearSearchComparisons(head1, key);
std::cout << "Comparisons done to find " << key <<": "<< comparisons << '\n';
*/


