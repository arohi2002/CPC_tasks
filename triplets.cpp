#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
    int n;
    cin>>n;
	int ans = 0;
	for (int i = 1; i <= n;i++) {
		for (int j = i; j <= n; j++) {
			int x = i * i + j * j;
			int y = sqrt(x);
			if (y * y == x && y <= n)
				ans++;
		}
	}
cout<<ans;
	return 0;
}
