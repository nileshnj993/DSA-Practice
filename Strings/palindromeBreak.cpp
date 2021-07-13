#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2){
    return s1<s2;
}

string breakPalindrome(string palindrome) {
    vector<string> v;
    for(int i=0; i<palindrome.size(); i++){
        string temp;
        temp = palindrome.substr(0,i) + palindrome.substr(i+1);
        v.push_back(temp);
    }
   
    sort(v.begin(), v.end(), comp);
     for(auto i: v){
        cout<<i<<"\n";
    }
    return v[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    cout<<breakPalindrome(s);
}