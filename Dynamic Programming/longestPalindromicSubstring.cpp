#include <bits/stdc++.h>
using namespace std;

string longestPalin(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(n,0)); // entire n*n matrix set to 0
    vector<int> start(n+1, INT_MAX); // start array so we can store first occurrence of all palindromes divided by lengths

    // substrings of length 1
    int maxLength = 1;
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        start[1] = min(start[1],i);
    }

    // substrings of length 2
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            maxLength = 2;
            start[2] = min(start[2], i);
        }
    }

    // substrings of length >=3
    for(int k=3;k<=n;k++){ // make k<n if entire string not counted as substring
        for(int i=0;i<n-k+1;i++){
            int subStart = i;
            int subEnd = subStart+k-1;
            if(s[subStart]==s[subEnd] && dp[subStart+1][subEnd-1]==1){
                dp[subStart][subEnd] = 1;
                maxLength = k;
                start[k] = min(subStart,start[k]);
            }
        }
    }

    return s.substr(start[maxLength],maxLength);
}

int main(){
    string s = "aabba";
    cout<<longestPalin(s)<<"\n";
}