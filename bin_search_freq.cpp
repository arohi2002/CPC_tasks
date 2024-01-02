#include<iostream>
using namespace std;
int count(int arr[], int key, int n){ 
int *l = lower_bound(arr, arr+n, key);

if (l == (arr + n) || *l != key){
	return 0;}
int *h = upper_bound(l, arr+n, key);	 
	
return h-l;
}

int main()
{
int arr[] = {1, 2, 2, 3, 3, 3, 3,3,3,3,3,4};
int key = 3; 
int n = sizeof(arr)/sizeof(arr[0]);
int c = count(arr, key, n);
printf(" the key %d occurs %d times ", key, c);
return 0;
}
