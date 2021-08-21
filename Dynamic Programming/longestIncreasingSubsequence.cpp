#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> arr){
    vector<int> lis(arr.size(),1);
    int i = 1;
    int j = 0;
    while(i<arr.size()){
        j=0;
        while(j<i){
            if(arr[i]>arr[j] && lis[i]<=lis[j]){
                lis[i] = lis[j]+1;
            }
            j++;
        }
        i++;
    }
    return *max_element(lis.begin(),lis.end());
}

int main(){
    vector<int> arr = {5,8,7,1,9};
    cout<<lis(arr);
}