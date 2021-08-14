// we have to find the sum of numbers between k1th smallest and k2th smallest number in a sorted array

#include <bits/stdc++.h>
using namespace std;    

int kSmall(vector<int> arr, int k){
    priority_queue<int> maxH;
    for(int i=0;i<arr.size();i++){
        maxH.push(arr[i]);
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    return maxH.top();
}

int main(){
    vector<int> arr = {1,3,12,5,15,11};
    int k1,k2;
    cin>>k1>>k2;
    int sum = 0;
    int low = kSmall(arr,k1);
    int high = kSmall(arr,k2);
    for(int i=0;i<arr.size();i++){
        if(arr[i]>low && arr[i]<high){
            sum+=arr[i];
        }
    }
    cout<<sum;
    cout<<"\n";
}