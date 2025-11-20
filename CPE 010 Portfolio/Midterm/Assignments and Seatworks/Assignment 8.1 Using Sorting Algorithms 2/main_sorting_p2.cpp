// C++ Program to demonstrate how to implement the quick
// sort algorithm
#include <bits/stdc++.h>
#include <vector>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }std::cout << '\n';
}

// Shell Sort
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// Merge Sort
void merge(std::vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    std::vector<int> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {

        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
    }
}

// QuickSort
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &vec, int low, int high) {

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of element just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(std::vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}



int main() {

    std::vector<int> vec = {12, 11, 13, 5, 6, 7};
    int n = vec.size();

    std::cout << "Unsorted: \n";
    for (auto i: vec)
        std::cout << i << " ";
    std::cout << '\n';

    // Sorting vec using mergesort
    mergeSort(vec, 0, n - 1);

    std::cout << "Sorted: \n";
    for (auto i: vec)
        std::cout << i << " ";
    std::cout << '\n';

    return 0;
}

// Quick sort
// std::vector<int> vec = {10, 7, 8, 9, 1, 5};
// int n = vec.size();
//
// std::cout << "Unsorted: \n";
// for (int i = 0; i < n; i++) {
//     std::cout << vec[i] << " ";
// }std::cout << '\n';
//
// // Calling quicksort for the vector vec
// quickSort(vec, 0, n - 1);
//
// std::cout << "Unsorted using quicksort: \n";
// for (auto i : vec) {
//     std::cout << i << " ";
// }

// Shell Sort
// int arr[] = {21, 36, 74, -2, 3}, i;
// int n = sizeof(arr)/sizeof(arr[0]);
//
// std::cout << "Array before sorting: \n";
// printArray(arr, n);
//
// shellSort(arr, n);
//
// std::cout << "\nArray after sorting: \n";
// printArray(arr, n);