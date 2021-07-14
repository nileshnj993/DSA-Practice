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

node *reverseRecursive(node *head){
    if(head->next == NULL || head==NULL){
        return head;
    }
    node *sHead = reverseRecursive(head->next); // get the head of every sub reversed linked list
    head->next->next = head;
    head->next = NULL;
    return sHead;
}

void reverseIterative(node *&head){
    node *current = head;
    node *prev = NULL;
    while(current!=NULL){
        node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    display(n1);
    // node *reversed = reverseRecursive(n1);
    // display(reversed); 
    reverseIterative(n1);
    display(n1);
}