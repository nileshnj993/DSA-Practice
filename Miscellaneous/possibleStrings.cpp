// find all possible strings that can be formed by replacing ? with either 1 or 0

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void backtrack(string s,int i){
    if(i==s.size()){
        res.push_back(s);
        return;
    }
    if(s[i]=='?'){
        s[i] = '0';
        backtrack(s,i+1);
        s[i] = '1';
        backtrack(s,i+1);
        // s[i] = '?';
    }
    else{
        backtrack(s,i+1);
    }
}
  
    

int main(){
    int i = 0;
    string s = "?1?1";
    string temp="";
    int n = s.size();
    backtrack(s,i);
    for(auto i : res){
        cout<<i<<"\n";
    }
}