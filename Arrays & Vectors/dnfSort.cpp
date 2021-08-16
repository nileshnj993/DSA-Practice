// sort an array that contains only 0's, 1's and 2's

#include <bits/stdc++.h>
using namespace std;

void disp(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void regularSort(vector<int> arr){
    sort(arr.begin(),arr.end());
    disp(arr);
}

void countSort(vector<int> arr){
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i=0;i<count0;i++){
        arr[i] = 0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i] = 1;
    }
    for(int i=count0+count1;i<arr.size();i++){
        arr[i] = 2;
    }
    disp(arr);
}

void dnfSort(vector<int> arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++; mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    disp(arr);
}

int main(){
    vector<int> arr = {0,2,1,2,2,1,0,0,1};
    regularSort(arr);
    countSort(arr);
    dnfSort(arr);
}

