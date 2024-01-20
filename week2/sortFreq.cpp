#include<iostream>
using namespace std;

struct el{
	int count, index, val;
};
bool mycomp(struct el a, struct el b){
	return (a.val < b.val);
}

bool mycomp2(struct el a, struct el b)
{
	if (a.count != b.count)
		return (a.count < b.count);
	else
		return a.index > b.index;
}

void sortByFreq(int arr[], int n)
{
	struct el e[n];
	for (int i = 0; i < n; i++) {

		e[i].index = i;
		e[i].count = 0;
		e[i].val = arr[i];
	}
	stable_sort(e, e + n, mycomp);
	e[0].count = 1;
	for (int i = 1; i < n; i++) {

		if (e[i].val == e[i - 1].val) {
			e[i].count += e[i - 1].count + 1;
			e[i - 1].count = -1;
			e[i].index = e[i - 1].index;
		}
		else
			e[i].count = 1;
	}

	stable_sort(e, e + n, mycomp2);
	for (int i = n - 1, index = 0; i >= 0; i--)
		if (e[i].count != -1)
			for (int j = 0; j < e[i].count; j++)
				arr[index++] = e[i].val;
}
int main(){
	int arr[] = { 2, 5, 2, 6, -1, 999, 5, 8, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFreq(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
