#ifndef SORTING_PT2_H
#define SORTING_PT2_H
#include <iostream>

static size_t comparisons = 0;
static size_t swaps = 0;

void resetCounters() {
    comparisons = 0;
    swaps = 0;
}
void printCounters() {
    std::cout << "Comparisons: " << comparisons << '\n';
    std::cout << "Swaps: " << swaps << '\n';
}
template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    swaps++;
}

template<typename T>
void printArray(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void randomNumberArray100(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100;
    }
}

// Shell Sort
template<typename T>
void shellSort(T arr[], size_t size) {
    // Start with a big gap, then reduce it
    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort
        for (size_t i = gap; i < size; i++) {
            T temp = arr[i];
            size_t j = i;

            // Shift earlier gap-sorted elements up until the correct location is found
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } else {
                    break;
                }
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

// Merge Sort
// Merge two sorted subarrays: arr[left..mid] and arr[mid+1..right]
template<typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    T* L = new T[n1];
    T* R = new T[n2];

    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            swaps++;
        } else {
            arr[k++] = R[j++];
            swaps++;
        }
    }

    // Copy
    while (i < n1) {
        arr[k++] = L[i++];
        swaps++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        swaps++;
    }

    delete[] L;
    delete[] R;
}

// Recursive merge sort
template<typename T>
void merge_sort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// QuickSort
// Partition function to place pivot in correct position
template<typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);

            // increment j if:
            // element > pivot

            // increment i if:
            // element < pivot; swap i and j; j++

            // if j == pivot; i++; swap j to pivot
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive quicksort
template<typename T>
void quicksort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

template<typename T>
void hybridQuickShellSort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        shellSort(arr + low, pivot - low);
        shellSort(arr + pivot + 1, high - pivot);
    }
}

#endif //SORTING_PT2_H