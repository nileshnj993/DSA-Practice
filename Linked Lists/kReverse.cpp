#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        
        node(int data){
            this->data = data;
            next = NULL;
        }
};


void display(node *head){
    if(head==NULL){
        cout<<"Empty list!\n";
        exit(0);
    }
    
    if(head->next==NULL){
        cout<<head->data<<"\n";
    }
    else{
        while(head!=NULL){
            if(head->next!=NULL){
                cout<<head->data<<"->";
            }
            else{
                cout<<head->data;
            }
            head = head->next;
        }
        cout<<"\n";
    }
}

node *kreverse(node *head, int k){
    if(head==NULL){
        return NULL;
    }
    node *current = head;
    node *prev = NULL;
    node *temp;
    int count = 0;
    while(current!=NULL && count<k){ // current != NULL needed in case less than k nodes there in a sublist
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }
    if(temp!=NULL){ // elements left to reverse
       head->next = kreverse(temp, k);
    }
    return prev;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    node *n7 = new node(7);
    node *n8 = new node(8);
    node *n9 = new node(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    int k = 3;
    display(n1);
    node *kreversed = kreverse(n1,k);
    display(kreversed); 
}