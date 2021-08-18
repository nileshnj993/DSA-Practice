// return number of elements where a[i]>a[j] and i<j

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int end){
    int count = 0;
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            count+=mid-i+1;
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
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
    for(int i=start; i<=end; i++){
        arr[i] = temp[k++];
    }
    return count;

}

int inversionCount(vector<int> &arr, int start, int end){
    if(start>=end){
        return 0;
    }
    int mid = (start+end)/2;
    int c1 = inversionCount(arr,start,mid); // inversions in left half
    int c2 = inversionCount(arr,mid+1,end); // inversions in right half
    int crossCount = merge(arr,start,end); // inversions in entire merged array
    return c1+c2+crossCount;
}

int main(){
    vector<int> arr = {0,5,2,3,1};
    int start = 0;
    int end = arr.size()-1;
    cout<<inversionCount(arr,start,end)<<endl;
}