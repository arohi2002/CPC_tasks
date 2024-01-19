#include<iostream>
#include<unordered_set>
using namespace std;

bool help(int arr[], int N){
	unordered_set<int> s;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		if (sum == 0 || s.find(sum) != s.end())
			return true;
		s.insert(sum);
	}
	return false;
}
int main(){
	int arr[] = {-3, 2, 3, 1, 6};
	int N = sizeof(arr) / sizeof(arr[0]);

	if (help(arr, N))
		cout << "Found ";
	else
		cout << "Not found";
	return 0;
}
