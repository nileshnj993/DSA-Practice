    // replace all spaces with %20
#include <bits/stdc++.h>
using namespace std;

string space20(string original){ // using extra string
    string result;
    for(char ch: original){
        if(ch==' '){
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
        }
        else{
            result.push_back(ch);
        }
    }
    return result;
}

// inplace solution

void space20Inplace(char *str){
    int spaces = 0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]==' '){
            spaces++;
        }
    }
    int index = strlen(str) + 2*spaces;
    str[index] = '\0';
    for(int i=strlen(str)-1; i>=0; i--){
        if(str[i] == ' '){
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index-=3;
        }
        else{
            str[index-1] = str[i];
            index--;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);
    cout<<space20(s)<<"\n";
    char str[1000];
    cin.getline(str,1000); // syntax for string arrays
    space20Inplace(str);
    cout<<str<<"\n";
}