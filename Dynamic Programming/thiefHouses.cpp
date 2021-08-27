// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int maxSum(int arr[], int n){
    if(n<=-1){ // no houses left
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a = maxSum(arr,n-1); // don't consider nth house and go 1 behind
    int b = arr[n] + maxSum(arr,n-2); // consider nth house and go 2 behind
    return dp[n] = max(a,b); // max sum is what we want
}

int main(){
    int n = 6;
    int a[] = {5,5,10,100,10,5};
    memset(dp,-1,sizeof(dp));
    cout<<maxSum(a,n-1)<<"\n";
}