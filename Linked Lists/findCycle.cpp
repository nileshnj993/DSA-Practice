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


void display(node *head){ // passing by value not reference
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

bool findLoop(node *head){
    node *slow = head;
    node *fast = head->next;
    bool cycle = false;
    while(true){
        if(slow==fast){
            cycle = true;
            break;
        }
        if(fast==NULL || fast->next==NULL){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return cycle;
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
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    //n8->next = n3;
    bool cycle = findLoop(n1);
    cout<<cycle;
}   