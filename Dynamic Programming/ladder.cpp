// Given a ladder of size N, and an integer K, write a function to compute number of ways to climb the ladder if you can take a jump of max k at every step.

#include <bits/stdc++.h>
using namespace std;

// f(x) is number of ways to reach step 'x'
// f(n) = f(n-1) + f(n-2) + f(n-3)

vector<int> dp(1005,-1);

int countWays(int n, int k){
    if(n==0){ // ways to get to 0th step
        return 1;
    }
    if(n<0){ // in case n-jump is negative
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0; // total ways
    for(int jump = 1; jump<=k; jump++){ // ways to get to n with 3 steps max is ways to get to n-1 + to n-2 + to n-3
        ans+=countWays(n-jump, k);
    }
    return dp[n] = ans;   
}

int countWaysBottomUp(int n, int k){
    int ans = 0;
    vector<int> steps(n+1,0);
    steps[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                steps[i]+=steps[i-j];
            }
        }
    }
    return steps[n];
}

// if given that k is 2
int countWays2(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 4;
    int k = 3;
    cout<<countWays(n,k)<<"\n";
    cout<<countWays2(4)<<"\n";
}

