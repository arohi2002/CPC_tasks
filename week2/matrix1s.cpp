#include<iostream>
using namespace std;
#define R 4 
#define C 4 
int help(bool mat[R][C]) {
	
	int row_i = -1 ;
	int maxCount = 0 ;
	
	for(int i = 0 ; i < R ; i++){
		int count = 0 ;
		for(int j = 0 ; j < C ; j++ ){
			if(mat[i][j] == 1){
				count++ ;
			}
		}
		if(count > maxCount){
			maxCount = count ;
			row_i = i ;
		}
	}
	
	return row_i ;
}

int main() 
{ 
	bool mat[R][C] = { {0, 0, 0, 1}, 
					{0, 1, 1, 1}, 
					{1, 1, 1, 1}, 
					{0, 0, 0, 0}}; 

	cout << "Index  " << help(mat); 

	return 0; 
} 
