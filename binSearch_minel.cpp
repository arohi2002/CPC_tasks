#include<iostream>
#include<vector>
using namespace std;

int minEl(int arr[], int l, int h){
	if (arr[l] <= arr[h]){
		return arr[l];
	}
	while (l <= h) {
		int mid=(l+h)/2;
		if (mid-1 >= 0 && arr[mid] < arr[mid - 1]) {
			return arr[mid];}
		if (arr[mid] > arr[h]){
			l = mid + 1;
		}else{
			h = mid - 1;
		}
	}
	return -1;
}
int main(){
	int arr[]={4,5,6,7,1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "min element :  "<< minEl(arr,0,n-1)<<endl;
	return 0;
}
