// connect ropes of different length to form one rope. cost of joining 2 ropes of length x and y is x+y. Find min cost of joining ropes. (similar to huffman algo, where we select min cost ropes at every step in a greedy manner)

#include <bits/stdc++.h>
using namespace std;

int minCostRopes(vector<int>arr){
    priority_queue<int,vector<int>,greater<int>> minH;
    for(int i=0;i<arr.size();i++){
        minH.push(arr[i]);
    }
    int cost = 0;
    while(true){
        
        if(minH.size()==1){ // last cost
            break;
        }
        int a = minH.top(); minH.pop(); // min element 1
        int b = minH.top(); minH.pop(); // min element 2
        minH.push(a+b); // cost of joining min cost ropes
        cost+=a+b; 
    }
    return cost;
}

int main(){
    vector<int> arr = {1,2,3,4,5}; // length of ropes
    cout<<minCostRopes(arr)<<"\n";
}