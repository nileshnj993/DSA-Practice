#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    vector<int> prefix;
    int minNo = *min_element(arr.begin(), arr.end());
    for(int i=0; i<arr.size();i++){
        arr[i]+=minNo;
    }
    k+=arr.size()*minNo;
    prefix[0] = arr[0];
    for(int i=1; i<arr.size();i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    int i = 0;
    int j =0;
    int count = 0;
    while(j<arr.size() && i<j){
        if((prefix[j] - prefix[i] + arr[i])==k){
            count++;
            i++;
            j=i+1;
        }
        else if((prefix[j] - prefix[i] + arr[i])>k){
            i++;
            j=i+1;
        }
        else{
            j++;

        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> arr = {10,2,-2,-20,10};
    int k = -10;
    cout<<cntSubarrays(arr,k);
}