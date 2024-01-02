#include<iostream>
using namespace std;

void unosrterArray(int arr[], int n){
int start = 0, end = n-1, i, max, min; 

for (start = 0; start < n-1; start++){
	if (arr[start] > arr[start+1])
	break;
}
if (start == n-1){
	cout << "array is sorted";
	return;
}
for(end = n - 1; end > 0; end--){
	if(arr[end] < arr[end-1])
	break;
}

max = arr[start]; min = arr[start];
for(i = start + 1; i <= end; i++){
	if(arr[i] > max)
	max = arr[i];
	if(arr[i] < min)
	min = arr[i];
}
for( i = 0; i < start; i++){
	if(arr[i] > min){ 
	start = i;
	break;
	}	 
} 
for( i = n -1; i >= end+1; i--){
	if(arr[i] < max){
	end = i;
	break;
	} 
} 
cout << "unsorted subarray that will sort the array lies between "
	<< start << " and " << end;
return;
}

int main(){
	int arr[] = {8, 12, 20, 30, 23, 44, 33, 31, 35, 50, 78};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	unosrterArray(arr, arr_size);
	return 0;
}
