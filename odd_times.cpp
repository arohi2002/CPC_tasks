#include<iostream>
using namespace std;
int oddNumberOfTimes(int arr[], int n){
	for (int i = 0; i <n; i++) {	
		int count = 0;	
		for (int j = 0; j <n; j++){
			if (arr[i] == arr[j])
				count++;
		}
		if (count%2!= 0)
			return arr[i];
	}
	return -1;
}
int main()
	{
		int arr[] = { 1,2,3,3,4,1,2,3,4 };
		int n = sizeof(arr) / sizeof(arr[0]);
		cout << "number which occurs odd number of times is "<<oddNumberOfTimes(arr, n)<<endl;
		return 0;
	}
