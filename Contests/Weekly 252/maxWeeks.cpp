// There are n projects numbered from 0 to n - 1. You are given an integer array milestones where each milestones[i] denotes the number of milestones the ith project has.

// You can work on the projects following these two rules:

// Every week, you will finish exactly one milestone of one project. You must work every week.
// You cannot work on two milestones from the same project for two consecutive weeks.
// Once all the milestones of all the projects are finished, or if the only milestones that you can work on will cause you to violate the above rules, you will stop working. Note that you may not be able to finish every project's milestones due to these constraints.

// Return the maximum number of weeks you would be able to work on the projects without violating the rules mentioned above.

// Input: milestones = [1,2,3]
// Output: 6
// Explanation: One possible scenario is:
// ​​​​- During the 1st week, you will work on a milestone of project 0.
// - During the 2nd week, you will work on a milestone of project 2.
// - During the 3rd week, you will work on a milestone of project 1.
// - During the 4th week, you will work on a milestone of project 2.
// - During the 5th week, you will work on a milestone of project 1.
// - During the 6th week, you will work on a milestone of project 2.
// The total number of weeks is 6.

#include <bits/stdc++.h>
using namespace std;

bool descending(int num1, int num2){
    return num1>num2;
}

long long numberOfWeeks(vector<int>& milestones) {
    long long int maxEle = *max_element(milestones.begin(), milestones.end()); // largest number in array
    long long int sum = 0; // sum of all elements in array
    for(int i=0;i<milestones.size();i++){
        sum+=milestones[i];
    }
    if(maxEle <= sum-maxEle){ // if the sum of other numbers is greater than the max element, then all milestones can be completed. So just return sum of array.
        return sum;
    }
    return 2*(sum-maxEle)+1; // if max element is greater than sum, then we can't complete all milestones. Return 2*(sum-maxEle) for number of iterations until everything becomes 0 except maxEle. +1 because of one last milestone completed of maxEle
}

int main(){
    vector<int> milestones = {6,5,4,2};
    cout<<numberOfWeeks(milestones);
}