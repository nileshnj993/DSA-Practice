#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int start, int end){
    int i = start;
    int mid = (start+end)/2;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]< arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    int k = 0;
    for(i=start; i<=end; i++){
        arr[i] = temp[k++];
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr,mid+1,end);
    return merge(arr,start, end);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {4,2,1,5,3};
    int start, end;
    start = 0;
    end = arr.size()-1;
    mergeSort(arr, start, end);
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<"\n";
}