#include <iostream>
#include <vector>
#include <chrono>

int linearSearch(const std::vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> sizes = {100000, 10000000, 100000000};

    for (int n : sizes) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = i;

        int key = -1;


        auto start1 = std::chrono::high_resolution_clock::now();
        linearSearch(arr, key);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto timeLinear = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        binarySearch(arr, key);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto timeBinary = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();

        std::cout << "Input size: " << n << "\n";
        std::cout << "Linear Search (Worst Case): " << timeLinear << " µs\n";
        std::cout << "Binary Search (Worst Case): " << timeBinary << " µs\n\n";
    }

    return 0;
}
