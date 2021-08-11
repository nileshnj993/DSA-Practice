#include <bits/stdc++.h>
using namespace std;

int ksmallest(vector<int> arr, int k){
    priority_queue<int> maxH;
    for(int i=0;i<arr.size();i++){
        maxH.push(arr[i]);
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    return maxH.top();
}

int klargest(vector<int> arr, int k){
    priority_queue<int,vector<int>,greater<int>> minH;
    for(int i=0;i<arr.size();i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            minH.pop();
        }
    }
    return minH.top();
}

int main(){
    vector<int> arr = {7,10,4,3,20,15};
    int k;
    cin>>k;
    cout<<ksmallest(arr,k)<<"\n";
    cout<<klargest(arr,k)<<"\n";
}