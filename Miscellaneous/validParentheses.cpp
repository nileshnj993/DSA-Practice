#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    if(s==""){ // empty string
        return 0;
    }
    int length = 0;
    stack<int> st;
    st.push(-1); // in case of (), 1 - (-1) needed to get 2
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            if(!st.empty()){ // stack not empty - to handle cases like )()()
                st.pop();
            }
            if(!st.empty()){ // 
                length = max(length, i-st.top()); // current - top to check length of subsequence
            }
            else{ // if stack is empty now, it means there are more ) than (. So we must keep a mark at the index where latest ) appeared in order to find correct length.
                st.push(i);
            }
        }
    }
    return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s = "(())";
    cout<<longestValidParentheses(s)<<"\n";
}