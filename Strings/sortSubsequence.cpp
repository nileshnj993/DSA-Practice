#include <bits/stdc++.h>
using namespace std;

void subsequence(string s, string o, vector<string> &v){
    if(s.size()==0){ // no character left to choose
        v.push_back(o); // o is each possible subsequence
        return;
    }
    char ch = s[0]; // 0th character in whatever left of string. We have to choose whether to consider this or not
    string reduced_input = s.substr(1); // input string for next recursive call
    subsequence(reduced_input, o+ch, v); // consider ch
    subsequence(reduced_input, o, v); // don't consider ch
}

bool compare(string a, string b){
    if(a.size()!=b.size()){
        return a.size() < b.size();
    }
    else{
        return a<b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    subsequence(s, output, v);
    // cout<<"[";
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<",";
    // }
    // cout<<"]";
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
   
}