#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1,s2;
    public:
        void push(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        void pop(){
            if(s1.size()==0){
                return;
            }
            s1.pop();
        }
        int front(){
            if(s1.size()==0){
                return -1;
            }
            return s1.top();
        }
        int size(){
            return s1.size();
        }
        bool empty(){
            if(s1.size()==0){
                return true;
            }
            return false;
        }
};

class queueOptimal{
    stack<int> s1;
    public:
        int flag = 0;
        void insert(int x){
            int y;
            if(!s1.empty()){
                y = s1.top();
                s1.pop();
                insert(x);
            }
            if(flag==0){
                s1.push(x);
                flag = 1;
            }
            s1.push(y);
                       
        }

        void push(int x){
            insert(x);
        }
        
        void pop(){
            s1.pop();
        }
         bool empty(){
            if(s1.size()==0){
                return true;
            }
            return false;
        }
        int size(){
            return s1.size();
        }
         int front(){
            if(s1.size()==0){
                return -1;
            }
            return s1.top();
        }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }

}