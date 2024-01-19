#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void foursum(int arr[], int n, int x){
	unordered_map<int, pair<int, int> > mp;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			mp[arr[i] + arr[j]] = { i, j };
        }}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if (mp.find(x - sum) != mp.end()) {
				pair<int,int> pr = mp[x - sum];
				if (pr.first != i && pr.first != j
					&& pr.second != i && pr.second != j) {
					cout << arr[i] << ", " << arr[j] << ", "
						<< arr[pr.first] << ", "
						<< arr[pr.second];
					return;
				}
			}
		}
	}
}

int main(){
	int arr[] = { 15, 20, 30, 44, 1, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 100;
	foursum(arr, n, x);
	return 0;
}
