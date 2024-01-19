#include<iostream>
using namespace std;

bool compare(int x, int y){
	return abs(x) < abs(y);
}
void sumCloseZero(int arr[], int n){
	sort(arr, arr + n, compare);
	int min = INT_MAX, x, y;
	for (int i = 1; i < n; i++) {
		if (abs(arr[i - 1] + arr[i]) <= min) {
			min = abs(arr[i - 1] + arr[i]);
			x = i - 1;
			y = i;
		}
	}
	cout << "two elements : "
		<< arr[x] << " and " << arr[y];
}

int main(){

	int arr[] = { 1, 60, -10, 70, -80, 85 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sumCloseZero(arr, n);
	return 0;
}
