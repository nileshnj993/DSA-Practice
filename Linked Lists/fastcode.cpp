#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL); if uncommented, it expects cin first before outputting any statements
    int choice;
    cout<<"1.Print 1\n2.Print 2\n";
    cin>>choice;
    if(choice==1){
        cout<<"one";
    }
    else if(choice==2){
        cout<<"two";
    }
    else{
        cout<<"invalid";
    }
}