#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
int pivot=arr[high];
int i=(low-1);
for(int j=low;j<=high;j++){
	if(arr[j]<pivot){
	i++;
	swap(arr[i],arr[j]);
	}
}
swap(arr[i+1],arr[high]);
return (i+1);
}
			
void quickSort(int arr[],int low,int high){
if(low<high){
	int pindex=partition(arr,low,high);
	quickSort(arr,low,pindex-1);
	quickSort(arr,pindex+1,high);
}
}
			

int main() {
int arr[]={1,6,4,9,4,3};
int n=sizeof(arr)/sizeof(arr[0]);
quickSort(arr,0,n-1);
cout<<"Sorted Array\n";
for(int i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
return 0;
}

