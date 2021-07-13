#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string s1){
    int count = 0;
    int start = 0;
    int finalStart = -1;
    int min = INT_MAX;
    string substr="";
    unordered_set<char> s;
    
    for(int i=0; i<s1.size(); i++){
        s.insert(s1[i]);
    }
    for(char ch: s){
        substr+=ch;
    }
    
    unordered_map<char,int> m1; // fp
    unordered_map<char,int> m2; // fs
     for(int i=0; i<substr.size(); i++){ // substring hashmap
        char ch = substr[i];
        m1[ch]++;
    }

    for(int i=0; i<s1.size(); i++){ // big string hashmap
        char ch = s1[i];
        m2[ch]++;
        if(m1[ch]!=0 && m2[ch]<=m1[ch]){ // for counting how many characters matched till now
            count++;
        }
        // have all characters been matched
        if(count==substr.size()){ // start contracting and remove either characters not present or duplicate elements
            while(m1[s1[start]]==0 || m2[s1[start]] > m1[s1[start]]){ // doesn't exist or duplicate
                m2[s1[start]]--;
                start++;
            }
        
            int windowSize = i-start+1; // number of characters in window
            if(windowSize<min){
                min = windowSize;
                finalStart = start;
            }
        }  
   }
   if(finalStart==-1){
       return "";
   }
   else{
       return s1.substr(finalStart, min);
   }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    cout<<smallestWindow(s)<<"\n";

}