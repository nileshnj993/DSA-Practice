// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

// Example
// s = "mom"
// The list of all anagrammatic pairs is [m,m] and [mo,om], hence output is 2

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