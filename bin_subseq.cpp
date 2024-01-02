#include<iostream>
using namespace std;

int subseqLength(int arr[],int n){
	vector<int> res;
	res.push_back(arr[0]);
	for (int i = 1; i < n; i++){
		if(arr[i]>res.back()){
			res.push_back(arr[i]);
		}else{
			int l = lower_bound(res.begin(), res.end(),arr[i])- res.begin();
			res[l] = arr[i];
		}
	}
	return res.size();
}
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Length of longest increasing subsequence is %d\n", subseqLength(arr,n));
	return 0;
}
