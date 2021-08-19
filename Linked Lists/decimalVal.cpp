// Given a singly linked list of 0s and 1s, the task is to find its decimal equivalent. Decimal Value of an empty linked list is considered as 0.

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int x){
            data = x;
            next = NULL;
        }
};

// more efficient
int decimalEfficient(node *head){
    if(head==NULL){
        return 0;
    }
    int res = 0;
    while(head!=NULL){
        res=(res*2)+head->data;
        head = head->next;
    }
    return res;
}


int decimal(node *head){
    if(head==NULL){
        return 0;
    }
    int decimal = 0;
    stack<int> st;
    while(head!=NULL){
        st.push(head->data);
        head = head->next;
    }
    int power = 0;
    while(!st.empty()){
        decimal+=pow(2,power)*st.top();
        power++;
        st.pop();
    }
    return decimal;
}

int main(){
    node *n1 = new node(0);
    node *n2 = new node(1);
    node *n3 = new node(1);
    n1->next = n2;
    n2->next = n3;
    cout<<decimal(n1)<<"\n";
    cout<<decimalEfficient(n1)<<"\n";
}