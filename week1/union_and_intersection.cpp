#include<iostream>
using namespace std;
void Unionfun(int arr1[], int arr2[], int s1, int s2)
{
	int i = 0, j = 0;
	while (i < s1 && j <s2) {
		if (arr1[i]<arr2[j]){
			cout << arr1[i] << " ";
            i++;
    }
		else if(arr2[j] < arr1[i]){
			cout << arr2[j] << " ";
                   j++;
    }
		else{
			cout << arr2[j] << " ";
            j++;
			i++;
		}
	}
	while (i <s1){
		cout << arr1[i] << " ";
        i++;}

	while (j <s2){
		cout << arr2[j] << " ";
        j++;
}}
void intersection(int arr1[], int arr2[], int s1, int s2)
{
    int i = 0, j = 0;
    while (i < s1 && j <s2) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else 
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
	int arr1[] = { 1, 4, 5, 6 ,8,9};
	int arr2[] = { 2, 3, 5,6, 7 };
	int s1= sizeof(arr1)/sizeof(arr1[0]);
	int s2= sizeof(arr2)/sizeof(arr2[0]);
	cout<<"union is"<<endl;
	Unionfun(arr1, arr2, s1, s2);
	cout<<endl;
	cout<<"intersection of arrays:"<<endl;
	intersection(arr1,arr2,s1,s2);
	return 0;
}
