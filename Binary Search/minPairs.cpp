// Given 2 non empty arrays, find the pair of numbers(one from each) whose absolute difference is minimum

#include <bits/stdc++.h>
using namespace std;

pair<int,int> minPair(vector<int> arr1, vector<int> arr2){
    pair<int,int> result;
    int diffMin = INT_MAX;
    for(int i=0;i<arr1.size();i++){
        int firstElement = arr1[i]; // first element of pair
        auto it = lower_bound(arr2.begin(),arr2.end(),firstElement) - arr2.begin(); // first value >= first element in second array
        if(it>=1 and abs(firstElement-arr2[it-1]<diffMin)){ // checking value one before lower bound if exists
            diffMin = abs(firstElement-arr2[it-1]);
            result.first = firstElement;
            result.second = arr2[it-1];
        }
        if(it!=arr2.size() and arr2[it]-firstElement < diffMin){ // element is found
            diffMin = abs(arr2[it] - firstElement);
            result.first = firstElement;
            result.second = arr2[it];
        }
    }
    return result;
}

int main(){
    vector<int> arr1 = {-1,5,10,20,3};
    vector<int> arr2 = {26,134,135,15,17};
    sort(arr2.begin(), arr2.end()); // sorted because we will be using lower_bound on it
    pair<int,int> result = minPair(arr1,arr2);
    cout<<result.first<<" "<<result.second<<"\n";
}