#include<iostream>
using namespace std;

int missingNumber(int arr[],int n){
	int x=n+1;
    int total= (x)*(x+1)/2;
    for (int i = 0; i < n; i++){
        total -= arr[i];
    }
    return total;
}
int main(){
	int arr[] = { 1, 2, 3,4,6,7,8 };
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"missing number is : " <<missingNumber(arr, n)<<endl;
	return 0;
}

