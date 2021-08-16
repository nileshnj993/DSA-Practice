// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// KADANE ALGO

#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>arr){
    int sum = 0;
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return max;
}

int main(){
    vector<int> arr = {1,-3,5,6,2,-5,1};
    cout<<maxSum(arr)<<"\n";
}


