#include <bits/stdc++.h>
using namespace std;

// same as finding subarrays with given sum

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> arr = {1,3,2,1,4,1,3,2,1,1,2}; // sizes of plots
    int k = 8; // size of plot needed
    // find start and end index in arr where exact k unit size is obtained
    vector<int> prefix;
    prefix.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        prefix.push_back(prefix[i-1] + arr[i]);
    }
    // for(auto i : prefix){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";

    // APPROACH 1 - O(N^2)
    // int i = 0;
    // int j = 1;
    // while(i<arr.size()-1){
    //     while(j<arr.size()){
    //         if((prefix[j]-prefix[i]+arr[i])==k){
    //             cout<<i<<" "<<j<<"\n";
    //             i++;
    //             j=i+1;
    //             break;
    //         }
    //         else if((prefix[j]-prefix[i]+arr[i])<k){
    //             j++;
    //         }
    //         else{
    //             i++;
    //             j=i+1;
    //         }
    //     }
    // }

    // APPROACH 2 - O(NlogN)
    // for(int i=0;i<arr.size()-1;i++){
    //     auto it = find(prefix.begin(), prefix.end(), k-arr[i]+prefix[i]);
     
    //     if(it!=prefix.end()){
    //         cout<<i<<" "<<it-prefix.begin()<<"\n";
    //     }
    // }

    // APPROACH 3 - sliding window O(N)
    int sum = 0;
    int i = 0; int j = 0;
    while(j<arr.size()){
        sum+=arr[j]; // expand window
        j++;

        while(sum>k && i<j){ // contract window
            sum-=arr[i];
            i++;
        }
        
        if(sum==k){
            cout<<i<<" "<<j-1<<"\n";
        }
    }
}

