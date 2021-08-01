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
   long long numWeeks = 0;
   sort(milestones.begin(), milestones.end(), descending);
   int numZeros = 0;
   int i = 0;
   
    vector<int> pos = {0,1};
    while(true){
        numWeeks++;
        milestones[pos[i]]--;
        if(milestones[pos[i]]==0){
            numZeros++;
            if(numZeros==milestones.size()){
                break;
            }
            pos[1]++;
            i=0;
        }
        else{
            i++;
            if(i==pos.size()){
                i=0;
            }
            if((numZeros==milestones.size()-1 && milestones[0]>1 || numZeros==milestones.size())){
                break;
            }
        }
    }
   return numWeeks;
}

int main(){
    vector<int> milestones = {5,2,1};
    cout<<numberOfWeeks(milestones);
}