#include<bits/stdc++.h>
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

node * reverseNum(node *&head){
    if(head==NULL){
        return NULL;
    }
    node *prev = NULL;
    node *curr = head;
    while(curr!=NULL){
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void disp(node *head){
    while(head!=NULL){
        cout<<head->data;
        head = head->next;
    }
}

node *addNum(node *first, node *second){
    int sum;
    int carry = 0;
    node *dummy = new node(0);
    node *temp = dummy;
    while(first!=NULL || second!=NULL){
        sum = 0;
        if(first!=NULL){
            sum+=first->data;
            first = first->next;
        }
        if(second!=NULL){
            sum+=second->data;
            second = second->next;
        }
        sum+=carry;
        carry = sum/10;
        node *i = new node(sum%10);
        temp->next = i;
        temp = i;
    }
    if(carry!=0){
        node *i = new node(carry);
        temp->next = i;
    }
    return dummy->next;
}

int main(){
    node *n1 = new node(3);
    node *n2 = new node(8);
    node *n3 = new node(9);
    node *n4 = new node(6);
    node *n5 = new node(5);
    n1->next = n2; // 28
    n3->next = n4;
    n4->next = n5; // 165
    // disp(n1);
    // cout<<"\n";
    // disp(n3);
    // cout<<"\n";
    n1 = reverseNum(n1);
    n3 = reverseNum(n3);
    // disp(n1);
    // cout<<"\n";
    // disp(n3);
    node *res = addNum(n1,n3);
    res = reverseNum(res);
    disp(res);
    cout<<"\n";
}