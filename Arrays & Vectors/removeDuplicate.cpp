#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums){
    if(nums.size()==1){
        return 1;
    }
    if(nums.size()==0){
        return 0;
    }
    int unique = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            continue;
        }
        else{
            nums[unique] = nums[i-1];
            unique++;
            nums[unique] = nums[i];
        }
    }
    return unique+1;
}

int main(){
    vector<int> nums = {1,1,1,1,1,1,1,2};
    int count = removeDuplicates(nums);   
     for(int i=0;i<count;i++){
        cout<<nums[i]<<" ";
     }
    cout<<"\n";
}