#include <stdio.h>
void fun(int arr[], int size){
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (arr[i] <= arr[j])
				break;
		}
		if (j == size) 
			printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 15, 18, 5, 3, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fun(arr, n);
	return 0;
}
