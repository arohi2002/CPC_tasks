#include<iostream>
using namespace std;
int help(int arr[], int size) {
   int right = 0, left = 0;
   for (int i = 1; i < size; i++)
      right += arr[i];
      for (int i = 0, j = 1; j < size; i++, j++) {
         right -= arr[j];
         left += arr[i];
         if (left == right)
            return arr[i + 1];
      }
   return -1;
}
int main() {
   int arr[] = { 2, 3, 4, 1, 4, 5 };
   int size = sizeof(arr) / sizeof(arr[0]);
   cout << "Partition element: " << help(arr, size);
}