#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        bool duplicates = false;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                duplicates = true;
                break;
            }
        }
        return duplicates;
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout<<containsDuplicate(nums);
}