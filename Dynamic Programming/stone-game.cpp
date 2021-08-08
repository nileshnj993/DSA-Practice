#include<bits/stdc++.h>
using namespace std;

// there are n stones. Alice and Bob can pick either 1,2, or 3 stones. The loser is the one who cannot pick stones anymore. Alice starts.
const int N = 1e5;
vector<int> memo(N,-1);

bool winner(int n){
    if(n==0){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
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