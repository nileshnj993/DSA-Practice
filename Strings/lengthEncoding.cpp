#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    // vector<pair<char,int>> v;
    string result="";
    int i=0;
    while(i<s.size()){
        int count = 0;
        char initial = s[i];
        while(s[i]==initial){
            count++;
            i++;
        }
        // v.push_back({initial,count});
        result+=initial;
        result+=to_string(count);
    }
    // for(i=0; i<v.size(); i++){
    //     cout<<v[i].first<<" "<<v[i].second<<"\n";
    // }
    if(result.size()>=s.size()){
        cout<<s;
    }
    else{
        cout<<result;
    }
}