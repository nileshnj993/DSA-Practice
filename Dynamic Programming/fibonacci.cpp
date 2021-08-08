#include <bits/stdc++.h>
using namespace std;

int countRecursive = 0;
int countDP = 0;
const int N = 1e5;
int memo[N]; // memoization


int fibRecursive(int n){
    countRecursive++;
    if(n<=2){
        return 1;
    }
    return fibRecursive(n-1) + fibRecursive(n-2);
}

int fibDP(int n){
    countDP++;
    if(n<=2){
        return 1;
    }
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n] = fibDP(n-1) + fibDP(n-2);
    return memo[n];
}

int main(){ 
    int n;
    cin>>n;
    cout<<fibRecursive(n);
    cout<<"\n"<<"Recursive calls:"<<countRecursive<<"\n";
    cout<<fibDP(n)<<"\n";
    cout<<"Recursive DP calls:"<<countDP<<"\n";
}