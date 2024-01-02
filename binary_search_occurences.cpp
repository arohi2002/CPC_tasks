#include <iostream>
using namespace std;
int GetRightPosition(int arr[], int l, int r, int key){
	int m;
	while(r - l>1 ){
		m =(l+r)/2;
		if( arr[m] <= key ){
			l = m;}
		else{
			r = m;
	}}

	return l;
}

int GetLeftPosition(int arr[], int l, int r, int key){
	int m;
	while( r - l > 1 ){
			m =(l+r)/2;
		if( arr[m] >= key ){
			r = m;}
		else{
			l = m;
	}}

	return r;
}

int count(int arr[], int size, int key){
	int left = GetLeftPosition(arr, -1, size-1, key);
	int right = GetRightPosition(arr, 0, size, key);

	return (arr[left] == key && key == arr[right])?
		(right-left+1):0;
}

int main(){
	int arr[] = {1, 1, 2, 3, 3, 3, 3, 4, 5,5,6,6,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int key = 6;

	cout<< "the number of time this key occurs ->key : " << key << ": " << count(arr, size, key) << endl;

	return 0;
}

