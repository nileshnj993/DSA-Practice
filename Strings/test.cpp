#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    // getline(cin,s,'.'); // accept string until full stop present
    cout<<s<<"\n";
    for(char ch:s){
        cout<<ch<<",";
    }

    int n = 5; // for getting 5 strings and storing in a vector
    vector<string> v;
    string temp;
    while(n>0){
        getline(cin,temp);
        v.push_back(temp);
        n--;
    }
    cout<<"\n";
    for(string str:v){
        cout<<str<<",";
    }
}