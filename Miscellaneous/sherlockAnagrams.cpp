#include<bits/stdc++.h>
using namespace std;

int generateSubstring(string s){
   int anagrams = 0;
   unordered_map<string,int> m;
   for(int i=0; i<s.size();i++){
       for(int j=1; j<=s.size()-i; j++){
           string substring = s.substr(i,j);
           sort(substring.begin(),substring.end());
           if(m[substring]>0){
               anagrams+=m[substring];
               cout<<substring<<" ";
           }
           m[substring]++;
       }
   }
    return anagrams;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s = "character";
    int anagrams = generateSubstring(s);
    cout<<anagrams<<"\n";
}