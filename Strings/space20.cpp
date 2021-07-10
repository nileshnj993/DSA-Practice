// replace all spaces with %20
#include <bits/stdc++.h>
using namespace std;

string space20(string original){
    string result;
    for(char ch: original){
        if(ch==' '){
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
        }
        else{
            result.push_back(ch);
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    cout<<space20(s)<<"\n";
}