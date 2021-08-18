#include <bits/stdc++.h>
using namespace std;

vector<pair<char,int>> duplicates(string s){
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    vector<pair<char,int>> result;
    for(auto it : m){
        if(it.second>1){
            result.push_back(make_pair(it.first,it.second));
        }
    }
    return result;
}

int main(){
    string s = "geeksforgeeks";
    vector<pair<char,int>> result = duplicates(s);
    for(auto it:result){
        cout<<it.first<<":"<<it.second<<"\n";
    }
}