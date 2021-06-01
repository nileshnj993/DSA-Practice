#include <bits/stdc++.h>

using namespace std;

vector <string> fizzbuzz(int n){
    vector<string> v;
    for(int i = 1; i<=n; i++){
        if(i%3==0 && i%5==0){
            v.push_back("FizzBuzz");
        }
        
        else if(i%3==0){
            v.push_back("Fizz");
        }
        else if(i%5==0){
            v.push_back("Buzz");
        }
        else{
            v.push_back(to_string(i));
        }
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector <string> result = fizzbuzz(15);
    for(int i = 0; i<result.size(); i++){
        cout<<i+1<<":"<<result[i]<<"\n";
    }
}