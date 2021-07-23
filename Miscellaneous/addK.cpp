// Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

// Example

// n = 10
// queries = [[1,5,3], [4,8,7],[6,9,1]]

// Queries are interpreted as follows:

//     a b k
//     1 5 3
//     4 8 7
//     6 9 1
// Add the values of  between the indices  and  inclusive:

// index->	 1 2 3  4  5 6 7 8 9 10
// 	        [0,0,0, 0, 0,0,0,0,0, 0]
// 	        [3,3,3, 3, 3,0,0,0,0, 0]
// 	        [3,3,3,10,10,7,7,7,0, 0]
// 	        [3,3,3,10,10,8,8,8,1, 0]


#include <bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    return 5;
}   

int main(){
    vector<int> v = {1,2,3,4,5};
    auto it = *max_element(v.begin(), v.end());
    cout<<it;
}


