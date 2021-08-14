// given an array, print k most occurring elements

#include <bits/stdc++.h>
using namespace std;

vector<int> kFrequent(vector<int> arr, int k){
    vector<int> result;
    unordered_map<int,int> m;
    for(int i = 0; i<arr.size();i++){
        m[arr[i]]++; // map for frequency of each character
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH; // min heap so that min element are popped out and max stay inside
    for(auto it : m){ // loop through map
        minH.push(make_pair(it.second,it.first)); // push pair with frequency as first element as heaps use first element of pair to compare
        if(minH.size()>k){
            minH.pop(); // pop top most min element
        }
    }
    while(!minH.empty()){
        result.push_back(minH.top().second); // push remaining elements
        minH.pop();
    }
    return result;
}

int main(){
    vector<int> arr = {1,1,1,3,3,3,3,2,2,4};
    int k;
    cin>>k;
    vector<int> result = kFrequent(arr,k);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
}