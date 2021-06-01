#include <bits/stdc++.h>
using namespace std;

int trappedWater(vector<int> arr){
    int maxLeft = arr[0];
    int n = arr.size();
    vector<int> left; vector<int> right(n);
    left.push_back(arr[0]);
    right[n-1] = arr[n-1];
    int maxRight = arr[n-1];
    for(int i=1;i<n;i++){
        if(arr[i]>maxLeft){
            maxLeft = arr[i];
        }
        left.push_back(maxLeft);
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxRight){
            maxRight = arr[i];
        }
        right[i] = maxRight;
    }
    int water = 0;
    for(int i=0; i<n;i++){
        water+=min(right[i],left[i])-arr[i];
    }
    return water;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(water)<<"\n";
}