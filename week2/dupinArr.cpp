#include<iostream>
using namespace std;
vector<int> duplicates(int arr[], int n){
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int index = arr[i] % n;
		arr[index] += n;
	}
	for (int i = 0; i < n; i++) {
		if ((arr[i] / n) >= 2)
		ans.push_back(i);
	}
return ans;
}
int main(){
	int arr[] = { 1, 6, 3, 1, 3, 6, 6,2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The repeating elements are: \n";
	vector<int> ans = duplicates(arr, n);
	for (auto x : ans)
		cout << x << " ";
	return 0;
}
