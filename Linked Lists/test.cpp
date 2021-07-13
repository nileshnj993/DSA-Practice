#include <bits/stdc++.h>
using namespace std;

template <typename T>

class node{
    T data;
    node<T> *next;
    public:
        node(T data){
            this->data = data;
            next = NULL;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node<int> *n = new node<int>(10);
    // cout<<n->data; can only do this if data was a public variable
}