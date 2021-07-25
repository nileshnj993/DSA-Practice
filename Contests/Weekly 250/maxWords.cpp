// 5161. Maximum Number of Words You Can Type

// There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

// Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters){
    int count = 0;
  
    vector<char> broken;
    for(int i=0; i<brokenLetters.size();i++){
        broken.push_back(brokenLetters[i]);
    }
    vector<string> words;
    stringstream ss(text);
    string token;
    while(getline(ss,token,' ')){
        words.push_back(token);
    }
    for(int i=0; i<words.size();i++){
        string word = words[i];
        bool possible = true;
        for(int j=0; j<broken.size();j++){
            string check = "";
            check+=broken[j];
  
            if(word.find(check)!=-1){
                possible = false;
            }
            
        }
        if(possible==true){
            count++;
        }
  
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text = "hello world";
    string brokenLetters = "ad";
    cout<<canBeTypedWords(text,brokenLetters);
}