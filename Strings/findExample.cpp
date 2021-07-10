#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string paragraph = "This is just a test to verify the functioning of the find function";
    string word;
    getline(cin,word);
    if(paragraph.find(word)!=-1){
        cout<<"Word found!";
    }
    else{
        cout<<"Word not found!";
    }

}