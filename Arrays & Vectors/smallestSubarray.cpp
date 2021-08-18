// Given an array of integers (A[])  and a number x, find the size of the smallest subarray with sum greater than the given value.

#include <bits/stdc++.h>
using namespace std;

int smallest(vector<int> arr, int x){
    int sum = 0;
    int ans = INT_MAX;
    int end = 0;
    int start = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>x){
            return 1;
        }
        sum+=arr[i];
        if(sum>x){
            ans = min(ans, i-start+1);
        }
        while(sum>x){
            sum-=arr[start];
            start++;
            if(sum>x){
                ans = min(ans,i-start+1);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,4,45,6,0,19};
    int x = 51;
    cout<<smallest(arr,x)<<"\n";
}