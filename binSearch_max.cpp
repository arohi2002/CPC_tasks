#include<iostream>
using namespace std;

int maxel(int arr[], int l, int h){

	if (l == h){
		return arr[h];
    }
	int m =(l+h)/2;

	if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]){
		return arr[m];
    }
	else if (arr[m] < arr[m + 1]){
		return maxel(arr, m + 1, h);
	}else{
		return maxel(arr, l, m - 1);
}}
int main(){
	int arr[] = { 1, 3, 50, 10, 9, 7, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "max element: "<< maxel(arr, 0, n - 1);
	return 0;
}

