// Insertion sort in C++

#include <iostream>

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << '\n';
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step]; // store the array to be compared on the key variable
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Driver code
int main() {
  int data[] = {14, -3, 0, 9, 8};
  int size = sizeof(data) / sizeof(data[0]);
  
  std::cout << "Unsorted array: \n";
  printArray(data, size);
  
  std::cout << "Sorted array in ascending order:\n";
  insertionSort(data, size);
  printArray(data, size);
}
