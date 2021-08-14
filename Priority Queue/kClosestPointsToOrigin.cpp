// given a set of coordinates, find k closest podoubles to origin
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,pair<double,double>> ppi;

vector<pair<double,double>> kClosest(vector<pair<double,double>> v, double k){
    vector<pair<double,double>> result; // min distance points
    priority_queue<ppi> maxH; // max heap to pop max distance points
    double distance;
    for(double i=0;i<v.size();i++){
        // distance = sqrt(pow(v[i].first,2) + pow(v[i].second,2)); // first element of max Heap element pair = euclidian distance from origin
        distance = pow(v[i].first,2) + pow(v[i].second,2); // sqrt not needed as we can square on all sides
        maxH.push(make_pair(distance,v[i])); // making a pair of distance and the coordinates. we can make a pair of distance and the index as well to save space
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    while(!maxH.empty()){
        result.push_back(maxH.top().second); // push coordinates of min distance points
        maxH.pop();
    }
    return result;
}

int main(){
    vector<pair<double,double>> v = {{1,3}, {-2,2}, {5,8}, {0,1}};
    double k;
    cin>>k;
    vector<pair<double,double>> result = kClosest(v,k);
    for(int i=0; i<result.size();i++){
        cout<<result[i].first<<","<<result[i].second<<"\n";
    }
}