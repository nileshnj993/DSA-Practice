// Suppose there is a queue of n users and your task is to assign a username to them. The system works in the following way. Every user has preferred login in the form of a string ‘s’ s consists only of small case letters and numbers. User name is assigned in the following order s, s0, s1, s2….s11…. means first you check s if s is available assign it if it is already occupied check for s0 if it is free assign it or if it is occupied check s1 and so on… if a username is assigned to one user it becomes occupied for other users after him in the queue.


#include <bits/stdc++.h>
using namespace std;

vector<string> usernames(vector<string> names){
    vector<string> res;
    unordered_map<string,int> m;
    for(int i=0; i<names.size();i++){
        int j = 0;
        string name = names[i];
        if(m[name]==0){
            res.push_back(name);
        }
        else{
            string temp = name;
            while(m[name]!=0){
                name = temp;
                name+=to_string(j);
                j++;
            }
            res.push_back(name);
        }
        m[name]++;
    }
    return res;
}

int main(){
    vector<string> names = {"abc","bcd", "abc"};
    vector<string> res = usernames(names);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<"\n";
}