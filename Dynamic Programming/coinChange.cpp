// You are given coins of certain denominations, and an integer M representing target money. Find min coins required to make the target.

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1005,-1);

int countMin(vector<int> coins, int target){
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;   
    }
    int minVal = INT_MAX;
    if(dp[target]!=-1){
        return dp[target];
    }

    if(target>0){
        for(int i=0;i<coins.size();i++){
            int val = countMin(coins,target-coins[i]);
            if(val!=INT_MAX){
                minVal = min(minVal,val+1);
            }
            
        }  
    }
     return dp[target] = minVal;
}

int numWaysToReachTarget(vector<int> coins, int target){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    int ways = 0;
    for(int i=0;i<coins.size();i++){
       ways+=numWaysToReachTarget(coins,target-coins[i]);
    }
    return ways;
}

int main(){
    vector<int> coins = {1,2};
    int target = 4;
    cout<<numWaysToReachTarget(coins,target)<<"\n";
}