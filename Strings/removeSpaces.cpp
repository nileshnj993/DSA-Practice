#include <bits/stdc++.h>
using namespace std;

string removeSpace(string s){
    int i = 0;
    int j = 0;
    int count = 0;
    while(i<s.size()){
        if(s[i]==' '){
            i++;
            count++;
        }
        else{
            s[j] = s[i];
            i++;
            j++;
        }
    }
     s[j] = '\0';
     return s.substr(0,s.size()-count);   
}


int main(){
    string s;
    getline(cin,s);
    s = removeSpace(s);
    cout<<s<<"\n";
}