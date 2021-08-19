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

node *reverseSecondHalf(node *head){
    node *slow = head;
    node *fast = head;
    node *prevMid;
    while(fast!=NULL && fast->next!=NULL){
        prevMid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    node *current = slow;
    node *prev = NULL;
    while(current!=NULL){
        node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    prevMid->next = prev;
    return head;
    
}

int main(){
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    //node *n6 = new node(6);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    //n5->next = n6;
    n1 = reverseSecondHalf(n1);
    while(n1!=NULL){
        cout<<n1->data<<" ";
        n1 = n1->next;
    }
    cout<<"\n";
    
}