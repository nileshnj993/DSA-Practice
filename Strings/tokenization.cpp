#include <bits/stdc++.h>
using namespace std;

vector<string> usingStringstream(string s){
    stringstream ss(s); // stores string in form of a stream
    string token;
    vector<string> tokens;
    while(getline(ss,token,' ')){ // ss is read until ' ' occurs, and the string obtained so far is stored in token
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> usingStringtok(char *s){
    vector<string> tokens;
    char *token = strtok(s, " "); // reads first word until delimiter and stores state of string
    while(token!=NULL){ // returns null when no more words
        tokens.push_back(token);
        token = strtok(NULL," "); // we have to pass null to preserve state of string. If we pass the string it'll reset to start and only access first word.
    }
    return tokens;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);

    vector<string> tokensStream, tokensTok;

    tokensStream = usingStringstream(s);
    for(auto token : tokensStream){
        cout<<token<<",";
    }
    cout<<"\n";

    char s1[100];
    cin.getline(s1,100);
    tokensTok = usingStringtok(s1);
    for(auto token : tokensTok){
        cout<<token<<",";
    }
    cout<<"\n";
}