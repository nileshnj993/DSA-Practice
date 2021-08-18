#include <bits/stdc++.h>
using namespace std;

vector<string> substring(string s){
    vector<string> result;
    for(int i=0;i<s.size()-1;i++){
        for(int j=i+1;j<s.size()+1;j++){
            result.push_back(s.substr(i,j-i));
        }
    }
    return result;
}

int main(){
    string s = "abcd";
    vector<string> substrings = substring(s);
    for(auto i : substrings){
        cout<<i<<" ";
    }
    cout<<"\n";
}