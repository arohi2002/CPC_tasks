#include<iostream>
using namespace std; 

void help(int arr[], int n) { 
	int max = n - 1; 
	int min = 0; 
	int i; 
	int* s = new int[n];
	s[0] = -1;
	for (i = 1; i < n; i++) { 
		if (arr[i] <= arr[min]) { 
			min = i; 
			s[i] = -1; 
		} 
		else
			s[i] = min; 
	} 
	int* g = new int[n]; 
	g[n - 1] = -1; 
	for (i = n - 2; i >= 0; i--) { 
		if (arr[i] >= arr[max]) { 
			max = i; 
			g[i] = -1; 
		} 
		else
			g[i] = max; 
	} 
	for (i = 0; i < n; i++) { 
		if (s[i] != -1 && g[i] != -1) { 
			cout << arr[s[i]] 
				<< " " << arr[i] << " "
				<< arr[g[i]]; 
			return; 
		} 
	} 
	cout << "No triplet found"; 
	delete[] s; 
	delete[] g; 
	return; 
} 

int main() 
{ 
	int arr[] = { 12, 11, 10, 5, 6, 2, 30 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	help(arr, n); 
	return 0; 
} 

