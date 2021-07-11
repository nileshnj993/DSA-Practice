#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(string A, string B) 
{
        int ptr1 = 0;
        int ptr2 = 0;
        bool subseq = false;
        while(ptr2<=B.size()){
            if(ptr1==A.size()){
                subseq = true;
                break;
            }
            if(A[ptr1]==B[ptr2]){
                ptr1++;
                ptr2++;
            }
            else{
                ptr2++;
            }
        }
        return subseq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str, substr;
    getline(cin,str);
    getline(cin,substr);
    bool result = isSubSequence(substr,str);
    if(result==false){
        cout<<"Not a subsequence!\n";
    }
    else{
        cout<<"Subsequence!\n";
    }
}