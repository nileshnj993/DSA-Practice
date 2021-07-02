#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> T(1005,vector<int>(1005,-1)); // 2D array with dimensions of the values that change with every recursive call. This is used to store values of each return call to save time later.

// recursive function
int knapsack(vector<int> weights, vector<int> values, int w, int n){
    if(n==0 || w==0){ // base condition - smallest valid case is when either there are no items left or no capacity left in the knapsack
        return 0; // 0 profits made in this case 
    }

    if(T[n][w]!=-1){ // if already calculated and present in matrix, no need to calculate again
        return T[n][w];
    }

    if(weights[n-1]>w){ // can't fit in knapsack so move on to next item
        return T[n][w] = knapsack(weights, values, w, n-1); // as we start from nth item, we call with n-1. We then store it in the memoization matrix.
    }
    else{   //if(weights[n-1]<=w){
        return T[n][w] = max(knapsack(weights, values, w, n-1), values[n-1] + knapsack(weights, values, w-weights[n-1], n-1)); // we can either take the item or not. We want max profit so we return max of case where we take and case where we don't take
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> weights = {2,4,1,6,7}; // weights of items
    vector<int> values = {20,30,10,50,100}; // prices of items
    int capacity = 10; // max weight knapsack can hold
    cout<<"Max profit is:"<<knapsack(weights, values, capacity, weights.size())<<"\n";
}