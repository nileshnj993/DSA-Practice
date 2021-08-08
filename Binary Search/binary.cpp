#include <bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int> arr, int ele){
    sort(arr.begin(),arr.end());
    int start = 0;
    int end = arr.size()-1;
    bool found = false;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]>ele){
            end = mid-1;
        }
        else if(arr[mid]<ele){
            start = mid+1;
        }
        else{
            cout<<"Element "<<ele<<" found at position "<<mid<<"\n";
            found = true;
            break;
        }
    }
    return found;
}

int main(){
    vector<int> arr = {4,2,1,6,8,10};
    int ele;
    //cin>>ele;
    //binarysearch(arr,ele);
    //cout<<binary_search(arr.begin(),arr.end(),ele); // stl function that returns boolean value
    sort(arr.begin(),arr.end());
    cout<<lower_bound(arr.begin(),arr.end(),2) - arr.begin(); // first value >= to 2
    cout<<upper_bound(arr.begin(),arr.end(),2) - arr.begin(); // first value > 2
}