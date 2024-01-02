#include<iostream>
using namespace std; 

#define x -1 

void help(int mn[], int n) { 
int j = n - 1; 
for (int i = n-1; i>=0; i--) 
	if (mn[i] != x){ 
		mn[j] = mn[i]; 
		j--; 
	} 
} 

void merge(int mn[], int Narr[], int m, int n) { 
int i = n; 
int j = 0; 
int k = 0;
while (k < (m + n)) { 
	if ((j == n)||(i < (m + n) && mn[i] <= Narr[j])) { 
		mn[k] = mn[i]; 
		k++; 
		i++; 
	}else{ 
	mn[k] = Narr[j]; 
	k++; 
	j++; 
	} 
} 
} 

void print(int arr[], int n) { 
for (int i = 0; i < n; i++) {
cout << arr[i] << " "; 
cout << endl; 
} }

int main() {
int mn[] = {2, 8, x, x, x, 13, x, 15, 20}; 
int Narr[] = {5, 7, 9, 25}; 
	
int n = sizeof(Narr) / sizeof(Narr[0]); 
int m = sizeof(mn) / sizeof(mn[0]) - n; 

help(mn, m + n); 
merge(mn, Narr, m, n); 
print(mn, m+n); 

return 0; 
} 
