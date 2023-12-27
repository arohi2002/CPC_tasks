#include<iostream>
#include<unordered_map>
using namespace std;
void oddOccurences(int arr[], int n){
	unordered_map<int,int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	for (auto it: mp) {
		if (it.second % 2 != 0)
			cout << it.first << ", ";
	}
}

int main(){
	int arr[] = { 3,4,2,3,3,3,4,2,5,6,6,1};
	int n= sizeof(arr) / sizeof(arr[0]);
    cout<<"odd occurences: "<<endl;
	oddOccurences(arr, n);
	return 0;
}
