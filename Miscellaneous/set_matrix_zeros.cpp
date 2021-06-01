
#include <bits/stdc++.h>

using namespace std;

// Naive method - too slow - takes O(m*n) and space is also more as row and col arrays used
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin>>m>>n;
	int arr[m][n];
	int row[m];
	int col[n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
				cin>>arr[i][j];
				if(arr[i][j]==0){
					row[i]=0;
					col[j]=0;
				}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(row[i]==0 || col[j]==0){
				arr[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}

	// efficient approach
	int col0 = 1; // setting to true initially. If it is false, it means that the values in the 0th column have been set to 0 already
	rows = m;
	cols = n;
	for(int i=0;i<rows;i++){
		if(arr[i][0]==0){
			col0 = 0; // set to false if you find any value = 0 in the 0th column
		}
		for(int j=1;j<cols;j++){
			if(arr[i][j]==0){
				arr[i][0] = 0; // set dummy row matrix to 0 (0th row)
				arr[0][j] = 0; // set dummy col matrix to 0 (0th column)
			}
		}
	}
	for(int i = rows-1; i>=0; i--){
		for(int j=cols-1; j>=0; j--){
			if(arr[i][0]==0 || arr[0][j]==0){
				arr[i][j]=0;
			}
		}
		if(col0 ==0){
			arr[i][0] = 0;
		}
	}
}	
