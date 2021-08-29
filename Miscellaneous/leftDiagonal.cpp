// You are given a 2-D array of integers of size M X N. If the array is not a square array then make it one by filling the remaining positions with 1. Check if all elements present in the left diagonal occur in the matrix (apart from their occurrence in the left diagonal) strictly more than k times, where “k” is an integer provided as an input. If yes, print “Present” else print “Not Present”.

#include <bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> square){
    for(int i=0;i<square.size();i++){
        for(int j=0;j<square[i].size();j++){
            cout<<square[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool presentK(vector<vector<int>> arr, int m, int n, int k){
    int square = max(m,n);
    vector<vector<int>> res(square,vector<int>(square,1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res[i][j] = arr[i][j];
        }
    }
    disp(res);
    bool present = true;
    unordered_map<int,int> m1;
    for(int i=0;i<square;i++){
        for(int j=0;j<square;j++){
            m1[res[i][j]]++;
        }
    }
    for(int i=0;i<square;i++){
        if((m1[res[i][i]]-1)<=k){
            present = false;
            break;
        }
    }
    
    return present;
}

int main(){
    vector<vector<int>> arr = {{1,2,3}, {5,5,5}};
    int m = arr.size();
    int n = arr[0].size();
    bool res = presentK(arr,m,n,1);
    if(res){
        cout<<"Present\n";
    }
    else{
        cout<<"Not Present\n";
    }
}