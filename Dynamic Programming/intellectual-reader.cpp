// You will be given a list of articles with their page lengths and intellectual value coefficients. Given a limit to the number of pages you can read in a day, determine the maximum intellectual value you can achieve during one day.
// For example, your articles are of lengths articles = [2,2,3,4] and they are of intellectual value iv = [2,4,4,5]. If you can read p=15 pages in a day, what should you read? You have to read each article twice to gain value.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(1005, vector<int>(1005,-1));

int knapsack(vector<int> iv, vector<int> pages,int p, int n){
    if(p==0||n==0){
        return 0;
    }
    if(arr[p][n]!=-1){
        return arr[p][n];
    }

    if(pages[n-1]>p){
        return arr[p][n]=knapsack(iv,pages,p,n-1);
    }
    else{
        return arr[p][n]=max(knapsack(iv,pages,p-pages[n-1], n-1)+iv[n-1], knapsack(iv,pages,p,n-1));
    }
}

int maximalLearning(vector<int> iv, vector<int> articles, int p){
    vector<int> pages;
    for(int i=0;i<articles.size();i++){
        pages.push_back(articles[i]*2);
    }
    int n = articles.size();
    return knapsack(iv,pages,p,n);
}

int main(){
    int p = 15; // limit of pages that can be read
    vector<int> iv = {2,4,4,5};
    vector<int> articles = {2,2,3,4};
    cout<<maximalLearning(iv,articles,p)<<"\n";
}