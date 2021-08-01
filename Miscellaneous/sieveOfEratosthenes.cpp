// print count of prime numbers less than n

#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n){
    if(n<=2){
        return 0;
    }
    vector<bool> primes(n+1,true);
    int count = 0;
    for(int i=2; i*i<=n; i++){
        if(primes[i]==true){
            for(int j=i*i; j<=n; j+=i){
                primes[j] = false;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(primes[i]==true){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<countPrimes(n)<<"\n";
}