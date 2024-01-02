#include<iostream>
using namespace std;

double Findmedian(int arr1[], int arr2[], int n){
	int low = (int)-1e9, high = (int)1e9;
	int x = n;
	double ans = 0.0;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		int u = upper_bound(arr1, arr1 + n, mid) - arr1+ upper_bound(arr2, arr2 + n, mid) - arr2;
		if (u <= x){
			low = mid + 1;
		}else{
			high = mid - 1;
	}}

	ans = low;
	x--;
	low = (int)-1e9;
	high = (int)1e9;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		int u = upper_bound(arr1, arr1 + n, mid) - arr1
				+ upper_bound(arr2, arr2 + n, mid) - arr2;

		if (u <= x){
			low = mid + 1;
        }else{
			high = mid - 1;
	}}
	ans = (ans + low) / 2;

	return ans;
}

int main(){
	int arr1[] = { 1, 4, 5, 6, 10 };
	int arr2[] = { 2, 3, 4, 5, 7 };

	int n = sizeof(arr1) / sizeof(arr1[0]);
	double median = Findmedian(arr1, arr2, n);
	cout << "Median: " << median << endl;

	return 0;
}