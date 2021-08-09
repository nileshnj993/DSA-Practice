#include <bits/stdc++.h>
using namespace std;

double root(int n){ // answer will lie between 1 and m 
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

int main(){
    int n;
    cin>>n;
    cout<<root(n)<<"\n";
}