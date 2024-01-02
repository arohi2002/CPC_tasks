#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
	if (left > right){
		return -1;
    }
	int m = (left + right)/2;
	if (arr[m] == key){
		return m;
    }
	
	if (arr[left] <= arr[m]){
		if (key >= arr[left] && key <= arr[m]){
			return binarySearch(arr, left, m - 1, key);}
		return binarySearch(arr, m + 1, right, key);
	}

	if (key >= arr[m] && key <= arr[right]){
		return binarySearch(arr, m + 1, right, key);
    }
	return binarySearch(arr, left, m - 1, key);
}

int main()
{
	int arr[] = { 5,6,7,8,1,2,3,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 8;
	int i = binarySearch(arr, 0, n - 1, key);

	if (i != -1)
		cout << "Index at which key found is : " << i << endl;
	else
		cout << "Key was not found";
}
