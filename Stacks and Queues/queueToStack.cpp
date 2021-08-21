#include<bits/stdc++.h>
using namespace std;

class Stack{ // using 2 queues
    queue<int>q1,q2;
  
    public:
        void push(int x){
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }
        void pop(){
            if(q1.size()==0){
                return;
            }
            q1.pop();
        }
        int top(){
            if(q1.size()==0){
                return -1;
            }
            return q1.front();
        }
        int size(){
            return q1.size();
        }
        bool empty(){
            if(q1.size()==0){
                return true;
            }
            return false;
        }
};

class StackOptimal{ // using one queue
    queue<int> q;
    public:
        void push(int x){
            int s = q.size();
            q.push(x);
            for(int i=0;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }
        void pop(){
            if(q.size()==0){
                return;
            }
            q.pop();
        }
        int top(){
            if(q.size()==0){
                return -1;
            }
            return q.front();
        }
        bool empty(){
            if(q.size()==0){
                return true;
            }
            return false;
        }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}