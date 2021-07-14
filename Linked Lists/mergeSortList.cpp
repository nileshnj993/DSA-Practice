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

node *mergeList(node *head1, node*head2){
    node *i = head1;
    node *j = head2;
    node *mergeHead;
    if(i->data <= j->data){
        mergeHead = i;
        i = i->next;
    }
    else{
        mergeHead = j;
        j = j->next;
    }
    node *temp = mergeHead;
    while(i!=NULL && j!=NULL){
        
        if(i->data <= j->data){
            temp->next = i;
            temp = temp->next;
            i = i->next;
        }
        else{
            temp->next = j;
            temp = temp->next;
            j = j->next;
        }
    }
    if(i==NULL){
        while(j!=NULL){
            temp->next = j;
            temp = temp->next;
            j = j->next;
        }
    }
    else{
         while(i!=NULL){
            temp->next = i;
            temp = temp->next;
            i = i->next;
        }
    }
    return mergeHead;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // node *n1 = new node(1);
    // node *n2 = new node(5);
    // node *n3 = new node(7);
    // node *n4 = new node(10);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // display(n1);
    // node *n5 = new node(2);
    // node *n6 = new node(3);
    // node *n7 = new node(6);
    // n5->next = n6;
    // n6->next = n7;
    // display(n5);
    node *n1 = new node(1);
    node *n2 = new node(1);
    node *n3 = new node(2);
    node *n4 = new node(4);
    n1->next = n2;
    n3->next = n4;
    display(n1);
    display(n3);
    node *res = mergeList(n1,n3);
    display(res);
}