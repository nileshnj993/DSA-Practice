// given a sorted array that contains duplicates, find frequency of a particular element

#include <bits/stdc++.h>
using namespace std;

int frequency(vector<int>arr,int n){
    auto it = lower_bound(arr.begin(),arr.end(),n);
    if(it==arr.end()){
        return -1;
    }
    auto it2 = upper_bound(arr.begin(),arr.end(),n);
    return it2-it;
}

// last occurence - first occurence + 1 = number of occurences

int findFirstOccurence(vector<int>arr, int n){
    int start = 0;
    int end = arr.size()-1;
    int ans = -1; // -1 if not found
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==n){ // continue searching in left subarray
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>n){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int findLastOccurence(vector<int> arr, int n){
    int start = 0;
    int end = arr.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==n){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid]>n){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    int n;
    cin>>n;
    cout<<frequency(arr,n)<<"\n";
    cout<<findLastOccurence(arr,n)-findFirstOccurence(arr,n)+1<<"\n";
}