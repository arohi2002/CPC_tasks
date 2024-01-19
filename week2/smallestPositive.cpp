#include<iostream>
using namespace std;

int help(int A[], int n,bool a[]){
	for (int i = 0; i < n; i++) {
		if (A[i] > 0 && A[i] <= n)
			a[A[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		if (!a[i])
			return i;

	return n + 1;
}
int main()
{

	int arr[] = { 0, 10, 2, -10, -20 };
	int n = sizeof(arr) / sizeof(arr[0]);
    bool a[n+1];
	cout << help(arr, n,a);}

