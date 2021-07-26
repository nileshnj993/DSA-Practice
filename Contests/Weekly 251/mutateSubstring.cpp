#include <bits/stdc++.h>
using namespace std;

string maximumNumber(string num, vector<int>& change) {
   
    bool changed = false; // if mutated yet or not

    
    for(int i=0;i<num.size();i++){
        int curr = num[i] - '0'; // actual value
        int mutation = change[num[i]-'0']; // possible mutated value
        if(mutation>curr){ // if mutation greater
            num[i] = mutation+'0'; // mutate
            changed = true; // mark that mutation done to find substrings
        }
        else if(mutation>=curr &&changed==true){ // if mutation possible and earlier mutations already done (basically substring with length>1)
            num[i] = mutation+'0'; // mutate
        }
        else if(mutation<curr && changed==true){ // any time a break is located after changes have been made, break and return num
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

