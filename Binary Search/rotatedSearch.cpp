#include <bits/stdc++.h>
using namespace std;

// find an element in a sorted array that has been rotated about a pivot. eg - 4 5 6 7 0 1 2 3

int rotatedSearch(vector<int> arr, int key){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }

        if(arr[start] <= arr[mid]){ // we are on left half of line
            if(key>=arr[start] and key <= arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{ // right half
            if(key<=arr[end] and key>= arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1; // not found
}

int main(){
    int n;
    cin>>n;
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout<<rotatedSearch(arr,n)<<"\n";

}