// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool knapsackBottomUp(vector<int> arr, int sum, int n){
    bool memo[n+1][sum+1];
    for(int i=0;i<=n;i++){
        memo[i][0] = true;
    }
    for(int i=0;i<=sum;i++){
        memo[0][i] = false;
    }
    memo[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){ // if sum < last index number
                dp[i][j] = dp[i-1][j]; // don't consider the number so same as previous
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}


int knapsack(vector<int> arr, int sum, int n){ // won't work for large input due to stack recursive calls
    if(sum==0){ // found subset
        return 1;
    }
    if(n<=0){ // no subset
        return 0;
    }
    if(dp[n][sum]!=-1){ // already stored value
        return dp[n][sum];
    }
    if(arr[n-1]>sum){ // if value to be considered is bigger than sum, we don't consider it
        return dp[n][sum] = knapsack(arr,sum,n-1);
    }
    else{
        return dp[n][sum] = knapsack(arr,sum,n-1) || knapsack(arr,sum-arr[n-1],n-1); // we take both possibilities, one where we consider n-1th element and one where we don't consider. or of both because we just want to find if even one subset exists
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> arr = {3,34,4,12,6,2};
    int sum = 9;
    // int res = knapsack(arr,sum,arr.size());
    // if(res==1){
    //     cout<<"Yes\n";
    // }
    // else{
    //     cout<<"No\n";
    // }

    bool res = knapsackBottomUp(arr,sum,arr.size());
    if(res){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}