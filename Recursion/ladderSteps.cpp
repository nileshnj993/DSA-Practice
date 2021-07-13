#include <bits/stdc++.h>
using namespace std;

int findWays(int remainingSteps, int max){
    int count = 0;
    if(remainingSteps==0){
        return 1;
    }
    if(remainingSteps<0){
        return 0;
    }
    
    count+=findWays(remainingSteps-1,max);
    count+=findWays(remainingSteps-2,max);
    count+=findWays(remainingSteps-3,max);
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int total = 5;
    int max = 3;
    int count = 0;
    count=findWays(total,max);
    cout<<count<<"\n";
}