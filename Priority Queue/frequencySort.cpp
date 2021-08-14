// sort array based on descending order of frequency
#include <bits/stdc++.h>
using namespace std;    

vector<int> frequencySort(vector<int> arr){
    vector<int> result;
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    priority_queue<pair<int,int>> maxH;
    for(auto it : m){
        maxH.push(make_pair(it.second, it.first));
    }
    while(!maxH.empty()){
        int count = maxH.top().first;
        while(count!=0){
             result.push_back(maxH.top().second);
             count--;
        }
        maxH.pop();
    }
    return result;
}

int main(){
    vector<int> arr = {1,1,1,3,3,3,3,2,2,4};
    vector<int> result = frequencySort(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
}