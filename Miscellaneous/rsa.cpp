#include <bits/stdc++.h>
using namespace std;

string encrypt(string s){
    string c="";
    for(int i=0;i<s.size();i++){
        c+=to_string(s[i]-'a'+1); // getting int equivalent of text input to be encrypted
    }
    int crypt = stoi(c); // making it into int due to calculations later
    int p = 3; // prime number 1
    int q = 7; // prime number 2
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = 2; // e has to be between 1 and phi(n) and not be a factor of n
    while(e<phi){
        if(n%e!=0){
            break;
        }
        e++;
    }
    int initial = pow(crypt,e); // data^e
    c = to_string(initial%n); // data^e % n
    return c;
}

string decrypt(string s){
    int k = 2;
    int p = 3; // prime number 1
    int q = 7; // prime number 2
    int n = p*q;
    int e = 2;
    int phi = (p-1)*(q-1);
    string dc="";
    for(int i=0;i<s.size();i++){
        dc+=to_string(s[i]-'a'+1); // getting int equivalent of text input to be encrypted
    }
    int decr = stoi(dc); 
    int d = round((k*phi)/e);
    int final = pow(decr,d);
    dc=to_string(final%n);
    return dc;
}

int main(){
    cout<<"Enter string to be encrypted: ";
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
    }
    string crypt = encrypt(s);
    cout<<"Encrypted Text: "<<crypt<<"\n";
    cout<<"Decrypted Text: "<<decrypt(crypt)<<"\n";
}