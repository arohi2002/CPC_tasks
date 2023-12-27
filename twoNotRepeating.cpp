#include<iostream>
using namespace std;
vector<int> twoNonRepeating(int arr[], int n){
	sort(arr,arr+ n);
	vector<int>res;
	for (int i = 0; i<= n; i+=2) {
		if (arr[i] != arr[i + 1]) {
			res.push_back(arr[i]);
			i--;
		}
	}
	return res;
}

int main(){
	int arr[] = {1,2,1,3,3,2,5,6,4,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int>res=twoNonRepeating(arr, n);
	cout << "two non repeating numbers are "<<res[0]<<" & " <<res[1]<<endl;
}

