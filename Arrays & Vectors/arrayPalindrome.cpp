// Given an array of positive integers. We need to make the given array a ‘Palindrome’. The only allowed operation is”merging” (of two adjacent elements). Merging two adjacent elements means replacing them with their sum. The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.

#include <bits/stdc++.h>
using namespace std;

int palindromeOperations(vector<int>arr){
    int count = 0;
    int i = 0;
    int j = arr.size()-1;
    while(i<=j){
        if(arr[i]==arr[j]){ // subproblem reduces to i+1, j-1
            i++;
            j--;
        }
        else if(arr[i]>arr[j]){ // we will have to merge j side because it is lesser
            j--;
            arr[j]+=arr[j+1]; // merge j and j+1
            count++;
        }
        else{
            i++;
            arr[i+1]+=arr[i]; // merge i and i+1
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {11, 14, 13, 11};
    cout<<palindromeOperations(arr)<<"\n";
}