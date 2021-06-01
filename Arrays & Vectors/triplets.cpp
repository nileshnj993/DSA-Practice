#include <bits/stdc++.h>
using namespace std;

// one obvious approach is using the same logic as pairsum but with another loop for the third number - O(N^2)

// we can use 2 pointer approach to optimize in O(N) time + O(NlogN) for sorting
// Sorting taking extra NlogN time was a bottleneck in case of pairSum but here it's not as N^2 is the next best approach

vector<vector<int>> tripletSum(vector<int> v, int sum){
    sort(v.begin(),v.end());
    vector<vector<int>> result;

    for(int i=0;i<=v.size()-3;i++){

        // 2 pointer approach
        int j = i+1; // moves forward
        int k = v.size()-1; // moves backward
        while(j<k){
            int intermediateSum = v[i] + v[j] + v[k];
            if(intermediateSum<sum){
                j++;
            }
            else if(intermediateSum>sum){
                k--;
            }
            else if(intermediateSum==sum){
                result.push_back({v[i], v[j], v[k]});
                j++;
                k--;
            }
        }
    }
    return result;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int s = 18;

    vector<vector<int>> result = tripletSum(arr,s);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}