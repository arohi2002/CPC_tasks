#include<iostream>
#include<vector>
using namespace std; 
vector<int> nextPermutation(int n, vector<int> arr){
	if (n == 1) 
		return arr; 
        int i;
	for (i = n - 1; i > 0; i--) { 
		if (arr[i] > arr[i - 1]) 
			break; 
	} 
	if (i != 0){ 
		for(int j = n - 1; j >= i; j--) { 
			if (arr[i - 1] < arr[j]){
				swap(arr[i - 1], arr[j]); 
				break; 
			} 
		} 
	} 
	return arr; 
} 

int main(){ 
	
  vector<int> v;
  for(int i=0;i<5;i++){
    v.push_back(i+2);
  }
   for(int i=0;i<5;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
    int n=v.size();
	vector<int>res; 
	res = nextPermutation(n, v); 
	for (int i = 0; i < res.size(); i++) { 
		cout << res[i] << " "; 
	} 
}
