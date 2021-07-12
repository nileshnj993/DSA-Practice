#include <bits/stdc++.h>
using namespace std;

string uniqueSubstring(string s){
    int i = 0;
    int j = 0;
    int max = INT_MIN;
    int windowLength = 0;
    int start=-1;
    unordered_map<char,int> m;
    while(j<s.size()){
        if(m.count(s[j]) && m[s[j]]>=i){
            i = m[s[j]] + 1; // move start of window to one after previous occurrence
            windowLength = j-i;
        } // if present in map and present in current window
        
        m[s[j]] = j; // updating last occurrence
        windowLength++;
        j++;

        if(windowLength>max){
            max = windowLength;
            start = i; // to find start point of the max substring
        }
    }
    // cout<<start<<"\n"<<max;
    return s.substr(start,max);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    string res = uniqueSubstring(s);
    cout<<res<<"\n";
}