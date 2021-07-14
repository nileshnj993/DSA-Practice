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

int midpoint(node *head){
    node *i = head;
    node *j = head;
    while(i!=NULL){
        if(i->next==NULL){
            i=NULL;
        }
        else if(i->next->next == NULL){ // if even numbers - return left mid
            i = NULL;
        }
        else{
            i = i->next->next;
            j = j->next;
        }
        
    }
    return j->data;
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
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    display(n1);
    cout<< midpoint(n1) <<"\n";
}