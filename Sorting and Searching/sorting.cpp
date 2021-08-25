#include <bits/stdc++.h>
using namespace std;

vector<int> selection(vector<int> arr){
    int min;
    for(int i=0;i<arr.size()-1;i++){
        min = i; // position to swap
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min = j; // will store smallest number in array at end of loop
            }
        }
        swap(arr[i],arr[min]); // swap i and min
    }
    vector<int> res;
    for(auto i : arr){
        res.push_back(i);
    }
    return res;
}

vector<int> bubble(vector<int> arr){
    int flag = 0;
    for(int i=0;i<arr.size()-1;i++){ // we have to compare adjacent elements n-1 times
        flag = 0;
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                flag = 1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==0){
            break;
        }
    }
    vector<int> res;
    for(auto i : arr){
        res.push_back(i);
    }
    return res;
}

vector<int> insertion(vector<int> arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int val = arr[i];
        int hole = i;
        while(hole>0 && arr[hole-1]>val){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = val;
    }
    vector<int> res;
    for(auto i : arr){
        res.push_back(i);
    }
    return res;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
           i++;
           swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}


void quicksort(vector<int> &arr,int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }

    
}

int main(){
    vector<int> arr = {5,2,1,5,6,3};
    vector<int> res = selection(arr);
    for(auto i : res){
        cout<<i<<" ";
    }
    res = bubble(arr);
    for(auto i : res){
        cout<<i<<" ";
    }
    res = insertion(arr);
    for(auto i : res){
        cout<<i<<" ";
    }
    quicksort(arr,0,arr.size()-1);
    for(auto i : arr){
        cout<<i<<" ";
    }
   
}
