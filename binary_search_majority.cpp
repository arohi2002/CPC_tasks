#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
	if (right >= left){
		int mid = (left + right)/2; 
		if ( (mid == 0 || key > arr[mid - 1]) && arr[mid] == key ){
			return mid;
        }
		else if (key > arr[mid]){
			return binarySearch(arr, mid + 1,right, key);
		}else{
			return binarySearch(arr, left,mid - 1, key);
	}}
	return -1;
}


bool isMajority(int arr[], int n, int key){
	int i = binarySearch(arr, 0, n - 1, key);
	if (i == -1)
		return false;
	if (((i + n / 2) <= (n - 1)) &&
	arr[i + n / 2] == key)
		return true;
	else
		return false;
}

int main(){
	int arr[] = { 1, 2, 3, 3, 3, 3, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 3;
	
	if (isMajority(arr, n, key))
		cout << key << " appears more than "
			<< n / 2 << " times in arr[]"
			<< endl;
	else
		cout << key << " does not appear more than"
			<< n / 2 << " times in array" << endl;

	return 0;
}
