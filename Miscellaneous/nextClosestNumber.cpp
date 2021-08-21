#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int n){
    string s = "";
    while(n>0){
        s+=to_string(n%2);
        n=n/2;
    }
    while(s.size()!=8){
        s+='0';
    }
    reverse(s.begin(),s.end());
    return s;
}

int convertToDecimal(string s){
    int val = 0;
    int power = s.size()-1;
    for(int i=0;i<s.size();i++){
        val+=pow(2,power)*(s[i]-'0');
        power--;
    }
    return val;
}

int closestNum(string s){
    int onePos = -1;
    int i = s.size()-1;
    while(i>=0){
        if(s[i]=='1'){
            onePos = i;
            i--;
        }
        else if(s[i]=='0' && onePos!=-1){
            swap(s[i],s[onePos]);
            break;
        }

        if(onePos==-1){
            i--;
            continue;
        }
    }
    return convertToDecimal(s);
}



int main(){
    int n;
    cin>>n;
    string s = convertToBinary(n);
    int closest = closestNum(s);
    cout<<closest<<"\n";
}