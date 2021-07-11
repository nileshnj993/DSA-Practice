#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> v;
    
    for(int i=0; i<n;i++){
        string s;
        getline(cin,s);
        v.push_back(s);
    }
    cin.clear();
    int key;
    bool reverse;
    string comp;
    cin>>key;
     cin.clear();
    cin>>reverse;
     cin.clear();
    getline(cin,comp);
    vector<pair<string,string>> v1;
    for(int i=0;i<v.size();i++){
        pair<string, string> p;
        p = make_pair(v[i], v[i][key+1]);
        v1.push_back(p);
    }
    for(int i=0; i<v1.size() ; i++){
        cout<<v1[i].first<<" "<<v1[i].second<<"\n";
    }


}