#include<iostream>
using namespace std;

int count(int arr[], int n){
	int c = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				c++;

	return c;
}

int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " ans "
		<< count(arr, n);
	return 0;
}