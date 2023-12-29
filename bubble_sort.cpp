#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void print(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		cout << " " << arr[i];
}
int main()
{
	int arr[] = { 44,3,5,6,4,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	cout << "sorted array :\n";
	print(arr, n);
	return 0;
}
