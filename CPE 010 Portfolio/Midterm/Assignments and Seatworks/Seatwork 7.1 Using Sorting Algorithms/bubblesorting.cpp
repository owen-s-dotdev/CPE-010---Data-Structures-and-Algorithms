#include <iostream>

// perform bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size -1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  int data[] = {34, 44, 0, 10, -3};
  
  // find array's length
  int size = sizeof(data) / sizeof(data[0]);
  
  std::cout << "Unsorted array: \n";
  printArray(data, size);
  
  std::cout << "Sorted Array in Ascending Order using Bubble sort:\n";  
  bubbleSort(data, size);
  printArray(data, size);
  
  return 0;
}
