#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    string s1, s2;
    s1 = to_string(a);
    s2 = to_string(b);
    return s1>s2;
}

string vecToString(vector<int> v){
    string s="";
    for(int i=0; i<v.size(); i++){
        s+=to_string(v[i]);
    }
    return s;
}

bool comp(int n1, int n2){
    string s1, s2;
    s1 = to_string(n1);
    s2 = to_string(n2);
    string a = s1+s2;
    string b = s2+s1;
    cout<<a<<" "<<b<<"\n";
    return a>b;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v = {10,11,20,30,3};
    // sort(v.begin(), v.end());
    // //sort(v.begin(), v.end(), compare);
    // // for(auto i : v){
    // //     cout<<i<<" ";
    // // }
    // string s= vecToString(v);
    // string max = s;
    // while(next_permutation(v.begin(), v.end())){
    //     s = vecToString(v);
    //     if(s>max){
    //         max = s;
    //     }
    // }
  
    // cout<<max;

    sort(v.begin(), v.end(), comp);
    for(auto i: v){
        cout<<i;
    }
}