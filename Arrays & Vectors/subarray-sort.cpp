// Given an unsorted array Arr of size N. Find the subarray Arr[s...e] such that sorting this subarray makes the whole array sorted.

#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> v, int i, int n){
    if(i==0){
        return v[0]>v[1];
    }
    if(i==n-1){
        return v[n-1]<v[n-2];
    }
    return v[i]>v[i+1] || v[i]<v[i-1];
}

vector<int> subArraySort(vector<int> v, int n){
    int smallest = INT_MAX;
    int largest = INT_MIN;
    if(n==1){
        return {0,0};
    }

    for(int i=0;i<n;i++){
        if(outOfOrder(v,i,n)){
            smallest = min(smallest, v[i]);
            largest = max(largest, v[i]);
        }
    }
    int start = 0; int end = n-1;
    while(smallest>=v[start]){
        start++;
    }
    while(largest<=v[end]){
        end--;
    }
    if(smallest==INT_MAX){
        return {0,0};
    }
    return {start,end};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> v = {10,12,20,30,25,40,32,31,35,50,60};
    int n = v.size();
    vector<int> result;
    result = subArraySort(v,n);
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";
}

