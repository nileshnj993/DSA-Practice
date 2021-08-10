// there is a long wire which contains N bird nests at position x1,x2..xN.
// There are B(<=N) birds which become angry towards each other when put into a nest. Assign birds to nests such that min distance between any two birds is as large as possible. Return the min distance of separation

#include <bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int b, int n, vector<int> nests,int sep){
    int birds = 1;
    int location = nests[0]; // place first bird in first nest
    for(int i=1;i<n;i++){
        int currentLocation = nests[i];
        if(currentLocation - location >=sep){
            birds++;
            location = currentLocation;
            if(birds==b){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int b = 3;
    vector<int> nests = {1,2,4,8,9}; // possible separations are 0-8
    sort(nests.begin(),nests.end()); // needed to apply binary search
    int n = nests.size();
    int s = 0; // min gap between birds
    int e = nests[n-1] - nests[0]; // max gap between birds
    // s -> e forms a monotonic array
    int ans=-1;
    while(s<=e){
        int mid = (s+e)/2; // possible separation value
        bool canPlace = canPlaceBirds(b,n,nests,mid); // can i place b birds with n nests, and separation between birds as mid
        
        if(canPlace){
            s = mid+1; // search for greater separation
            ans = mid; // max separation till now
        }
        else{
            e = mid-1; // reduce separation
        }
    }
    cout<<ans<<"\n";
}