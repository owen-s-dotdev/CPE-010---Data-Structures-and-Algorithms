#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int sizes[] = {1000, 10000, 50000};

    for (int n : sizes) {
        std::vector<int> baseArr(n);
        for (int i = 0; i < n; i++) {
            baseArr[i] = i;
        }

        std::cout << "\n=== Input Size: " << n << " ===" << std::endl;

        std::vector<int> arrBest1 = baseArr;
        std::vector<int> arrBest2 = baseArr;

        clock_t start = clock();
        bubbleSort(arrBest1);
        clock_t end = clock();
        double bubbleBest = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort(arrBest2, 0, n - 1);
        end = clock();
        double mergeBest = double(end - start) / CLOCKS_PER_SEC;

        std::vector<int> arrWorst1 = baseArr;
        std::vector<int> arrWorst2 = baseArr;
        std::reverse(arrWorst1.begin(), arrWorst1.end());
        arrWorst2 = arrWorst1;

        start = clock();
        bubbleSort(arrWorst1);
        end = clock();
        double bubbleWorst = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort(arrWorst2, 0, n - 1);
        end = clock();
        double mergeWorst = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Bubble Sort (Best):  " << bubbleBest << " seconds\n";
        std::cout << "Bubble Sort (Worst): " << bubbleWorst << " seconds\n";
        std::cout << "Merge Sort (Best):   " << mergeBest << " seconds\n";
        std::cout << "Merge Sort (Worst):  " << mergeWorst << " seconds\n";
    }

    return 0;
}
