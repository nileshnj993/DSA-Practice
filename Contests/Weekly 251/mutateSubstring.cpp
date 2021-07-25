#include <bits/stdc++.h>
using namespace std;

string maximumNumber(string num, vector<int>& change) {
    string result = "";
   
    bool changed = false;

    
    for(int i=0;i<num.size();i++){
        int curr = num[i] - '0';
        int mutation = change[num[i]-'0'];
        if(mutation>curr){
            num[i] = mutation+'0';
            changed = true;
        }
        else if(mutation>=curr &&changed==true){
            num[i] = mutation+'0';
        }
        else if(mutation<curr && changed==true){
            return num;
        }
        
    }
    return num;
}

int main(){
    string num = "334111";
    vector<int> change = {0,9,2,3,3,2,5,5,5,5};
    cout<<maximumNumber(num,change);
}

