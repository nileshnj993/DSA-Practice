#include <bits/stdc++.h>
using namespace std;

int highestMountain(vector<int> arr){
    int n = arr.size();
    int largest = 0;
    for(int i=1;i<n-1;i++){ // first and last elements can't be peaks
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){ // check if peak
            // count backwards
            int count = 1; // current element counted as 1
            int j = i;

            // count backward
            while(j>=1 && arr[j]>arr[j-1]){ // stricly decreasing and less than 1 not possible as at least 1 element must be there in the mountain
                j--; // go backwards
                count++;
            }

            // count forward
            while(i<n-1 && arr[i]>arr[i+1]){ // strictly decreasing and i not bigger than array size itself else segmentation fault
                i++; // go front
                count++;
            }
            largest = max(largest, count);
        }
    }
    return largest;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> arr = {3,4,5,4,3,2,1,0,-2,-3};
    cout<<highestMountain(arr)<<"\n";
}