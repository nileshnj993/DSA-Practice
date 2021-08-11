// k sorted array means the right element for position i is in the range [i-k to i+k] in the array

#include <bits/stdc++.h>
using namespace std;

vector<int> ksort(vector<int> arr, int k){
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minH; // as smallest elements appear on top
    for(int i=0;i<arr.size();i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            result.push_back(minH.top());
            minH.pop();
        }
    }
    while(!minH.empty()){
        result.push_back(minH.top());
        minH.pop();
    }
    return result;
}

int main(){
    vector<int> arr = {6,5,3,2,8,10,9};
    int k = 3;
    vector<int> result = ksort(arr,k);
    for(auto i:result){
        cout<<i<<" ";
    }
    cout<<"\n";
}