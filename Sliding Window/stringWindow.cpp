#include <bits/stdc++.h>
using namespace std;

// Given one small and one big string, find smallest window in big string that contains all characters of big string
// if small string has duplicates, they must be present with same or higher count in window
// window can have additional characters 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2;
    int count = 0;
    int start = 0;
    int finalStart = -1;
    int min = INT_MAX;
    getline(cin,s1); // big string
    getline(cin,s2); // small string

    unordered_map<char,int> m1; // fp
    unordered_map<char,int> m2; // fs
    for(int i=0; i<s2.size(); i++){ // substring hashmap
        char ch = s2[i];
        m1[ch]++;
    }

    for(int i=0; i<s1.size(); i++){ // big string hashmap
        char ch = s1[i];
        m2[ch]++;
        if(m1[ch]!=0 && m2[ch]<=m1[ch]){ // for counting how many characters matched till now
            count++;
        }
        // have all characters been matched
        if(count==s2.size()){ // start contracting and remove either characters not present or duplicate elements
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
       cout<<"No window found!\n";
   }
   else{
       cout<<s1.substr(finalStart, min)<<"\n";
   }
    
}