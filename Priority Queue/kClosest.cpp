// give k numbers that are closest to x

#include <bits/stdc++.h>
using namespace std;

// class Compare{ // custom comparator
//     public:
//         bool operator()(pair<int,int> a, pair<int,int> b){
//             return a.first < b.first;
//         }
// };

vector<int> kclosest(vector<int> arr, int k, int x){
    vector<int> result;
    //priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxH; // max Heap because we want to retain the k closest
    priority_queue<pair<int,int>> maxH; // by default max Heap uses pair.first for comparison if a pair is used
    for(int i=0;i<arr.size();i++){
        maxH.push(make_pair(abs(arr[i]-x), arr[i])); // pair of difference of number and x, and number
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    while(!maxH.empty()){
        result.push_back(maxH.top().second);
        maxH.pop();
    }
    return result;
}

int main(){
    int x = 7;
    int k = 3;
    vector<int> arr = {5,6,7,8,9};
    vector<int> result = kclosest(arr,k,x);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
}