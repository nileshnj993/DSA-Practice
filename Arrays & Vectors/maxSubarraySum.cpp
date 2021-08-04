#include<bits/stdc++.h>
using namespace std;

// Return maximum consecutive subarray sum possible. If all -ve numbers then return 0.

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    int max=arr[0];
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>max){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
   
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> arr = {-1,2,3,4,-2,6,-8,3};
    cout<<"Maximum Subarray Sum is: "<<maxSubarraySum(arr)<<"\n";
}
