#include <bits/stdc++.h>
using namespace std;


string extractTokenAtKey(string str, int key){ // extract only key element of each column separated string
    stringstream ss(str);
    string token;
    
    while(getline(ss,token, ' ') && key>1){
        key--;
        //cout<<token;
    }
    return token; // returning value in token when key becomes <=1 indicating that we have reached correct column
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return stoi(key1) < stoi(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string,string> s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1 < key2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    cin.get(); // for taking care of /n after entering number of elements
    vector<string> v; // storing all strings (column separated numbers)
    string s;
    for(int i=0; i<n;i++){
        getline(cin,s);
        v.push_back(s);
    }

    int key; // which column to use for comparison
    string reversal; // whether to reverse or not
    string comp; // numeric or lexico comparison
    cin>> key >> reversal >> comp; // we can't use getline as false and numeric will be considered as same string

    vector<pair<string,string>> v1; 
    for(int i=0; i<n; i++){
        v1.push_back({v[i], extractTokenAtKey(v[i], key)}); // making vector of string and key    
    }


    if(comp=="numeric"){
        sort(v1.begin(), v1.end(), numericCompare);
    }
    else{
        sort(v1.begin(), v1.end(), lexicoCompare);
    }

    if(reversal=="true"){
        reverse(v1.begin(), v1.end());
    }

    for(int i=0;i<v1.size();i++){
        cout<<v1[i].first<<"\n"; // no need to print key
    }
}