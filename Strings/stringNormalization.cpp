#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    s[0] = toupper(s[0]);
    for(int i = 1; i<s.size(); i++){
        if(s[i-1]==' '){
            s[i] = toupper(s[i]);
        }
        else{
            s[i] = tolower(s[i]);
        }
    }
    cout<<s;
}