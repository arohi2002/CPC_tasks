#include<iostream>
using namespace std;
void findTwo(int arr[], int n){
	int i, j;
	cout << "Repeating : ";
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				cout << arr[i] << " ";
				break;
			}
		}
	}
}

int main(){
	int arr[] = { 4, 2, 4, 5, 2, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findTwo(arr, n);
	return 0;
}
