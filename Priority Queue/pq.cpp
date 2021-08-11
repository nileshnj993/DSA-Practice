// heaps are binary trees that are complete excluding last level.
// in max heap, all children are lesser than parent, and in min heap, all children are greater than parent.

/*

        100
        / \
      30   40
     /  \  / \
    23       20 
    
    This is not a valid heap as right child of 40 exists but right of 30 and left of 40 don't. Go in left to right order */

// push - O(log n) as we traverse height of tree in worst case (if push element > root) and height = log(n)
// popMin / popMax - O(log n) - removing min or max node
// getMin/ getMax - O(1)

// adding custom comparator functions for sorting order in heaps
class Compare{
    public:
        bool operator()(int a,int b){ // function overloading
            return a<b; // descending order
        }
};




#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;

int main(){
    vector<int> arr = {2,1,4,6,5,9,7};
    // sort(arr.begin(),arr.end(),greater<int>()); 
    priority_queue<int, vector<int>, greater<int>> minH;
    priority_queue<int, vector<int>, Compare> customMinH;
    for(int i=0;i<arr.size();i++){
        minH.push(arr[i]); // it will get inserted such that heap is in ascending order from top to bottom. Time complexity = O(logN) as binary tree operation
        customMinH.push(arr[i]);
    }
    while(!minH.empty()){
        cout<<minH.top()<<" ";
        minH.pop();
    }
    cout<<customMinH.top();
    cout<<"\n";
}