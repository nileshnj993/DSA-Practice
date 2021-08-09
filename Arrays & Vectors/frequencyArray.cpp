// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}


vector<int> sortFrequency(vector<int> arr){
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto it: m){
        v.push_back(it);
    }
    sort(v.begin(),v.end(),comp);
    vector<int> result;
    for(int i=0;i<v.size();i++){
        while(v[i].second!=0){
            result.push_back(v[i].first);
            v[i].second--;
        }
    }
    return result;
}


int main(){
    vector<int> arr = {2,3,1,3,2};
    vector<int> res = sortFrequency(arr);
    for(int i: res){
        cout<<i<<" ";
    }
    cout<<"\n";
}