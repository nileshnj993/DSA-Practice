// given n and m, find nth root of m
#include <bits/stdc++.h>
using namespace std;

double root(int m, int n){ // answer will lie between 1 and m 
    double low = 1;
    double high = m;
    double limit = 1e-6;
    while((high-low) > limit){
        double mid = (high+low)/2;
        if(pow(mid,n)>m){
            high = mid;
        }
        else{
            low = mid;
        }   
    }
    return low;
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<root(m,n)<<"\n";
}