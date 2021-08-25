#include <bits/stdc++.h>
using namespace std;

vector<int> findMissing(vector<int> arr){
    int n = arr.size();
    vector<int> count(n+3,0);
    for(int i = 0; i<n; i++){
        count[arr[i]]++;
    }
    //cout<<count[1];
    vector<int> res(2);
    int pos = 0;
    for(int i=1;i<=n;i++){
        if(count[i]==0){
            res[pos++] = i;
        }
    }
 
    return res;
}

vector<int> findMissingAlternate(vector<int> arr){
    int n = arr.size();
    int m1,m2;
    vector<int> res(2);
    int sum = 0; int sumSquared = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=n){
            sum+=arr[i];
            sumSquared+=arr[i]*arr[i];
        }
    }
    int sumOfMissing = abs(n*(n+1)/2 - sum);
    int sumOfMissingSquared = abs(n*(n+1)*(2*n+1)/6 - sumSquared);
    int xy = (sumOfMissing*sumOfMissing) - (sumOfMissingSquared);
    int differenceOfMissingSquared = sumOfMissingSquared - xy;
    m1 = sqrt((sumOfMissingSquared-differenceOfMissingSquared)/2);
    m2 = sumOfMissing-m1;
    res[0] = m1;
    res[1] = m2;
    return res;
}


int main(){
    vector<int> arr = {1,2,3,4,7,8,9,10};
    vector<int> res = findMissing(arr);
  
    res = findMissingAlternate(arr);
    cout<<"Missing:"<<res[0]<<" "<<res[1]<<"\n";
}