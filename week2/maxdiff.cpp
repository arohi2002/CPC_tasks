#include<iostream>
using namespace std;
int maxdiff(int arr[], int n){	 
int mx = arr[1] - arr[0];
for (int i = 0; i < n; i++){
	for (int j = i+1; j < n; j++){	 
	if (arr[j] - arr[i] > mx) 
		mx = arr[j] - arr[i];
	} 
}		 
return mx;
} 
int main(){
int arr[] = {1, 2, 90, 10, 110};
int n = sizeof(arr) / sizeof(arr[0]);
cout << "max difference " << maxdiff(arr,n );

return 0;
}
