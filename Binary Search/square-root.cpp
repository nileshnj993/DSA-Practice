#include <bits/stdc++.h>
using namespace std;

double root(int n){ // answer will lie between 1 and n
   long mid;
   long start = 1;
   long end = n;
   while(start<=end){
       mid = (start+end)/2;
       if(mid*mid==n){
           return mid;
       }
       else if(mid*mid>n){
           end = mid-1;
       }
       else{
           start = mid+1;
       }
   }
   if(mid*mid>n){
       return mid-1;
   }
   return mid;
}

double rootPrecision(double n, double p){
    double limit = pow(10,-p-1);
    double start = 1;
    double end = n;
    while((end-start) > limit){
        double mid = (start+end)/2;
        if(mid*mid==n){
            return mid;
        }
        if((mid*mid) > n){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return start;
}

int main(){
    double n;
    cin>>n;
    cout<<root(n)<<"\n";
    cout<<rootPrecision(n,3);
}