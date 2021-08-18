// move negative numbers in array to leftmost corner such that they appear before all positive numbers

#include <bits/stdc++.h>
using namespace std;

void negativeSort(vector<int> arr){
    int i = 0;
    int j = arr.size()-1;
    while(i<=j){
        if(arr[i]<0 && arr[j]<0){
            i++;
        }
        else if(arr[i]>0 && arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    negativeSort(v);
}