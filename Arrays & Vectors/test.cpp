#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// size of vector
	vector<int> v = {1,2,3,4,5};
	cout<<v.size()<<"\n";

	// capacity of vector
	v.push_back(15);
	cout<<v.size()<<"\n"; // number of elements
	cout<<v.capacity()<<"\n"; // total space - doubles everytime max size is crossed, so when 6th element was added, capacity of 5 became 10 (5x2)
	
	// printing the elements
	for(int i = 0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";

	// popping elements
	v.pop_back();
	for(int i = 0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";

	// fill constructor - to populate n number of elements with particular value
	int numberOfElements = 5;
	int initialValue = 10;
	// vector<int> visited(1000,0); - commonly used usecase
	vector<int> v1(numberOfElements, initialValue);
	for(int i = 0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}
	cout<<"\n";

	// 2D Vectors
	vector<vector<int>> arr = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	for(int i = 0; i<arr.size(); i++){
		for(int j = 0; j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		} cout <<"\n";
		
	}
	arr.push_back(v1);
	for(int i = 0; i<v1.size();i++){
		cout<<arr[3][i]<<" ";
	}
	cout<<"\n";

}