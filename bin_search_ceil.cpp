#include<iostream>
using namespace std;
int ceiling(int arr[], int low, int high, int key){
	int mid;
	if (key <= arr[low]){
		return low;
    }
	if (key > arr[high]){
		return -1;}

	mid = (low + high)/2; 

	if (arr[mid] == key){
		return mid;
    }
	else if (arr[mid] < key) {
		if (mid + 1 <= high && key <= arr[mid + 1])
			return mid + 1;
		else
			return ceiling(arr, mid + 1, high, key);
	}else{
		if (mid - 1 >= low && key > arr[mid - 1])
			return mid;
		else
			return ceiling(arr, low, mid - 1, key);
	}
}

int main(){
	int arr[] = { 1, 2, 8, 10, 10, 12, 19 ,44};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 5;
	int index = ceiling(arr, 0, n - 1, key);
	if (index == -1)
		cout << "Ceiling of "<< key<< " doesn't exist ";
	else
		cout << "ceiling of " << key << " is " << arr[index];

	return 0;
}
