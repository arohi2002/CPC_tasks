#include<iostream>
using namespace std;
bool ThreeSum(int arr[], int n, int sum){
	int l, r;
	sort(arr, arr+n);
	for (int i = 0; i < n-2; i++) {
		l = i + 1;
		r = n - 1;
		while (l < r) {
			if (arr[i] + arr[l] + arr[r] == sum) {
				printf("triplet is %d, %d, %d", arr[i], arr[l],arr[r]);
				return true;
			}
			else if (arr[i] + arr[l] + arr[r] < sum){
                l++;
            }else{
				r--;
		}}
	}
	return false;
}
int main(){
	int arr[] = { 1, 10,20,1,4,5};
	int sum = 22;
	int n = sizeof(arr)/sizeof(arr[0]);
	ThreeSum(arr,n, sum);
	return 0;
}

