// array of integers and k given. Find vector containing max for each and every contiguous array of size k
#include <bits/stdc++.h>
using namespace std;


int findMax(vector<int> arr, int start, int end){
    int maxVal = INT_MIN;
    for(int i=start; i<=end; i++){
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

vector<int> maxWindow(int k, vector<int> arr){
    vector<int> res;
    int i = 0;
    int j = 0;
    while(i<=arr.size()-k){
        j+=k;
        j--;
        if(j>arr.size()){
            break;
        }
        res.push_back(findMax(arr,i,j));
        i++;
        j=i;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int k = 3;
    // cin>>k;
    vector<int> arr = {1,2,3,1,4,5,2,3,6};
    vector<int> res = maxWindow(k,arr);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<"\n";
    
}