// given 2 sorted arrays, merge them into one common array

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeExtraSpace(vector<int> v1, vector<int> v2){
    vector<int> res;
    int i = 0;
    int j = 0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            res.push_back(v1[i]);
            i++;
        }
        else{
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        res.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

// vector<int> merge(vector<int> v1, vector<int> v2){

// }

int main(){
    vector<int> v1 = {1,4,7,8,10};
    vector<int> v2 = {2,3,9};
    vector<int> result = mergeExtraSpace(v1,v2);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
}