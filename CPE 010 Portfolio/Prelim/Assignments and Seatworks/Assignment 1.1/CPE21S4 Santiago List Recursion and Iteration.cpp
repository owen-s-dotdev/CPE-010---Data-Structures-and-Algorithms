#include <iostream>

// Sum of elements in list using Recursion
int sumRecur(int list[], int n);
// Sum of elements in list using Iteration
int sumIterate(int list[], int n) ;


int main() {
   int n;
   std::cout << "Enter number of elements: ";
   std::cin >> n;
   int list[n];
   for (int i = 0; i < n; i++) {
       std::cout<<"Enter element "<<i+1<<": ";
       std::cin >> list[i];
   }
   std::cout << "Sum of Numbers (Iteration): "<<sumIterate(list, n)<<'\n';;
   std::cout << "Sum of Numbers (Recur): "<<sumRecur(list, n)<<'\n';

   return 0;
}
int sumRecur(int list[], int n) {
   if (n == 0) {
       return 0;
   }
   return list[n - 1] + sumRecur(list, n - 1);
}
int sumIterate(int list[], int n) {
   int sum = 0;
   for (int i = 0; i < n; i++)
       sum += list[i];
   return sum;
}
