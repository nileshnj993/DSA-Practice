#include <bits/stdc++.h>
using namespace std;

vector<int> findOccurrences(string paragraph, string substr)
{
    vector<int> result = {};
    int i = 0;
    int index = paragraph.find(substr);

    if(index==-1){
        return result;
    }
    else{
        while(index !=-1){
            result.push_back(index);
            i=index+1;
            index = paragraph.find(substr,i);
        }
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string paragraph;
    string substr;
    getline(cin,paragraph);
    getline(cin,substr);

    vector<int> ans = findOccurrences(paragraph, substr);
    if(ans.size()==0){
        cout<<"Not found!";
    }
    else{
        for(int pos:ans){
            cout<<"Found at position "<<pos<<"\n";
        }
    }
}