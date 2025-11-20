#include <iostream>

void linearSearchArr();
void binarySearchArr();
int binSearch(int arr[], int n, int target);

int main(){
	
	std::cout << "Linear Search \n";
	linearSearchArr();
	std::cout << '\n';
	
	std::cout << "Binary Search \n";
	binarySearchArr();
	std::cout << '\n';
	
	return 0;
}

void linearSearchArr(){
	int arrSize, dataFind, x;
	
	std::cout << "Enter array size: ";
	std::cin >> arrSize; std::cout << '\n';
	
	int arr[arrSize];
	for (int j = 0; j < arrSize; j++){
		std::cout << "Enter element " << j + 1 << ": ";
		std::cin >> x;
		arr[j] = x;
		std::cout << '\n';
	}
	
	std::cout << "Enter data to be searched: ";
	std::cin >> dataFind;
	for (int i = 0; i < arrSize; i++){
		if(arr[i] == dataFind){
			std::cout << "Data found at index: " << i << '\n';
			return;
		}
	}
	std::cout << "Data: (" << dataFind << ") wasn't found in the array. \n";
}

void binarySearchArr(){
	int arrSize, dataFind, arr[arrSize], x, f;
	
	std::cout << "Enter array size: ";
	std::cin >> arrSize; std::cout << '\n';
	
	for (int j = 0; j < arrSize; j++){
		std::cout << "Enter element " << j + 1 << ": ";
		std::cin >> x;
		arr[j] = x;
		std::cout << '\n';
	}
	
	std::cout << "Enter data to be searched: ";
	std::cin >> dataFind;
	
	f = binSearch(arr, arrSize, dataFind);
	
	if (f == -1){
		std::cout << "Element is not found. \n";
	}
	else{
		std::cout << "Element found at index: " << f;
	}
}

int binSearch(int arr[], int n, int target) {
   int left = 0, right = n - 1;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target)
         return mid;
      else if (arr[mid] < target)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1; 
}



 
