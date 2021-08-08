#include<bits/stdc++.h>
using namespace std;

// there are n stones. Alice and Bob can pick either 1,2, or 3 stones. The loser is the one who cannot pick stones anymore. Alice starts.

const int N = 1e5;
vector<int> memo(N,-1); // did not initialize as 0 because 0 represents losing state.

bool winner(int n){
    if(n==0){ // no more stones left to play - base case (should be least possible pick - 1 . eg if user can only pick 2,3,4 stones, case would be if(n==0 || n==1)
        return 0; // lost
    }
    if(memo[n]!=-1){
        return memo[n]; // if already saved
    }
    return(memo[n]=!(winner(n-1) & winner(n-2) & winner(n-3)));
}

int main(){
    int n; // number of total stones
    cin>>n;
    bool result = winner(n); // if 0, Alice loses. If 1, Alice wins.
    if(result==0){
        cout<<"Alice lost!"<<"\n";
    }
    else{
        cout<<"Alice won!"<<"\n";
    }
}