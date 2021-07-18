// 5814. Add Minimum Number of Rungs

// You are given a strictly increasing integer array rungs that represents the height of rungs on a ladder. You are currently on the floor at height 0, and you want to reach the last rung.

// You are also given an integer dist. You can only climb to the next highest rung if the distance between where you are currently at (the floor or on a rung) and the next rung is at most dist. You are able to insert rungs at any positive integer height if a rung is not already there.

// Return the minimum number of rungs that must be added to the ladder in order for you to climb to the last rung.

#include <bits/stdc++.h>
using namespace std;

int minRungs(vector<int> &rungs, int dist){
    int count = 0;
    int pos = 0;
    int k = 0;
    while(pos!=rungs[rungs.size()-1]){
        count+=(rungs[k]-pos)/dist;
        if((rungs[k]-pos)%dist!=0){
            count++;
        }
        count--;
        pos = rungs[k];
        k++;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> rungs = {3};
    int dist = 1;
    cout<<minRungs(rungs,dist)<<"\n";
    
   
}