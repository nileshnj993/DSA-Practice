// 2 arrays given, make a pair from both arrays such that absolute difference is minimum (closest to 0)

#include<bits/stdc++.h>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int minDiff = INT_MAX;
    pair<int,int> result;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0; int j=0;
    while(i<n1 && j<n2){
        int val = abs(a[i]-b[j]);
        if(val<minDiff){
            minDiff = val;
            result = make_pair(a[i],b[j]);
        }
        if(a[i]==b[j]){
            result = make_pair(a[i],b[j]);
            return result;
        }
        if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
        
    }
    return result;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> a = {23,5,10,17,30};
    vector<int> b = {26,134,135,14,19};
    pair<int,int> result = minDifference(a,b);
    cout<<result.first<<" "<<result.second<<"\n";
}