// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

#include <bits/stdc++.h>
using namespace std;

vector<int> findRepeatingandMissing(vector<int> arr){
    int n = arr.size();
    vector<int> arrCount(n+1,0);
    vector<int> res(2);
    for(int i=0;i<n;i++){
        arrCount[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(arrCount[i]==2){
            res[0] = i;
        }
        else if(arrCount[i]==0){
            res[1] = i;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4,4,6,7,8};
    vector<int> res = findRepeatingandMissing(arr);
    cout<<"Repeating:"<<res[0]<<"\n";
    cout<<"Missing:"<<res[1]<<"\n";
}