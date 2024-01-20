#include<iostream>
using namespace std;

void kthLargest(int arr[], int n, int k){
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
}

int main(){
	int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	kthLargest(arr, n, k);
}
