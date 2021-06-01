#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> formPair(vector<int> v, int sum){
    vector <int> pairNum;
    vector<vector<int>> returnVector;
    for(int i=0;i<v.size();i++){
        int firstNum = v[i];
        int secondNum = sum-v[i];
        auto it = find(v.begin()+i+1,v.end(),secondNum);
        if(it!=v.end()){
            secondNum = v[it-v.begin()];
            pairNum.push_back(firstNum);
            pairNum.push_back(secondNum);
            returnVector.push_back(pairNum);
            pairNum.clear();
        }
    }
    return returnVector;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v = {48,24,99,51,33,39,29,83,74,72,22,46,40,51,67,37,78,76,26,28,76,25,10,65,64,47,34,88,26,49,86,73,73,36,75,5,26,4,39,99,27,12,97,67,63,15,3,92,90};
    int sum = 50;
    vector<vector<int>> pair;
    pair = formPair(v,sum);
    if(pair.size()==0){
        cout<<"No such pair found!\n";
    }
    else{
        for(int i = 0; i<pair.size(); i++){
            for(int j=0;j<pair[i].size();j++){
                cout<<pair[i][j]<<" ";
            }
            cout<<"\n";
        }   
    }
}