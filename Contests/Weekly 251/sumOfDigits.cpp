#include <bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    int pos = 1;
    unordered_map<char,char> m;
    string num = "";
    for(int i=0;i<alphabets.size();i++){
        m[alphabets[i]] = pos;
        pos++;
    }
    for(int i=0;i<s.size();i++){
        num+=to_string(m[s[i]]);
    }
   
    // long val = stol(num);
    int sum = 0;
    for(int i=0;i<k;i++){
        sum = 0;
        for(int j=0;j<num.size();j++){
            cout<<sum<<" ";
            sum+=num[j]-'0';
        }
       
        num = to_string(sum);
    }
    return sum;
    
}

int main(){
    string s = "zbax";
    int k = 2;
    cout<<getLucky(s,k);
}
