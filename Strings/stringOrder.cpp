#include <bits/stdc++.h>
using namespace std;

static bool comp(string s1, string s2){
        return s1<s2;    
}

vector<string> orderString(string s[], int n){
        vector<string> v;
    	sort(s, s+n, comp);
    	v.push_back(s[0]);
    	v.push_back(s[n-1]);
    	return v;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s[] = {"a", "ab", "abc"};
    vector<string> v = orderString(s,3);
    for(auto i:v){
        cout<<i<<" ";
    }
}