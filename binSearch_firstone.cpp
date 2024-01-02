#include <iostream>
using namespace std;

int main(){
    int low,high,m,res;
    int arr[] = {0,0,1,1,1,1,1,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    low = 0;
    high = 10;
    while(low<=high){
        m=(low+high)/2;
        if(arr[m] == 1){
            res = m-1;
            high = m-1;
        }else{
            res = m;
            low = m+1;
        }
    }
    cout << res+1 << "\n";
    return 0;
}