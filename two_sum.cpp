#include<iostream>
using namespace std;

bool isPair(int arr[], int n, int x){
	for (int i = 0; i <n; i++) {
		for (int j=i+1; j <n; j++) {
			if (arr[i] + arr[j] == x) {
				return 1;
			}
		}
	}

	return 0;
}
int main(){
	int arr[] = {4,3,-2,0,-4,-1};
	int x = 2;
	int n= sizeof(arr)/sizeof(arr[0]);

	if (isPair(arr,n, x)) {
		cout << "Yes pair exists" << endl;
	}
	else {
		cout << "does not exist"<< endl;
	}

	return 0;
}