#include <bits/stdc++.h>
using namespace std;

// most efficient data structure for lookups is unordered set coz we get O(1) lookup

int longestBand(vector<int> arr){
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
       
        int largest = 1;

        // if(find(arr.begin(), arr.end(), arr[i]-1)==arr.end())
        for(auto element:s){
            int parent = element-1;
            // if parent in array, then ignore that element as it is a part of the subsqeuence
            if(s.find(parent)==s.end()){ // can't find parent, so start of new subsequence
                int next_no = element+1;
                int count = 1;
                while(s.find(next_no)!=s.end()){
                    next_no++;
                    count++;
                }
                if(count>largest){
                    largest = count;
                }
            }
        }
    return largest;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longestBand(arr)<<"\n";
}