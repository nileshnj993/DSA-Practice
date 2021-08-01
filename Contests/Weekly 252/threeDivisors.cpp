// Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

// An integer m is a divisor of n if there exists an integer k such that n = k * m.
// Input: n = 2
// Output: false
// Explantion: 2 has only two divisors: 1 and 2.
// Input: n = 4
// Output: true
// Explantion: 4 has three divisors: 1, 2, and 4.

#include <bits/stdc++.h>
using namespace std;

 bool isThree(int n) {
    int count = 2;
    for(int i=2; i<n;i++){
        if(count>3){
            break;
        }
        if(n%i==0){
            count++;
        }
    }
    if(count==3){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<isThree(n);
}