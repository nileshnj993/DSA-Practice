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

node *removeFromLast(node *head, int pos){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL && pos==1){
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    node *newHead = slow;
    int count = 0;
    while(count<pos){
        count++;
        fast = fast->next;
    }
    
    if(fast==NULL){
        newHead = slow->next;
        return newHead;
    }
    

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    if(pos==1){
        slow->next = NULL;
    }
    else{
        slow->next = slow->next->next;
    }
    
    return newHead;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // node *n1 = new node(1);
    // node *n2 = new node(2);
    // node *n3 = new node(3);
    // node *n4 = new node(4);
    // node *n5 = new node(5);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    node *n1 = new node(1);
    node *n2 = new node(2);
    n1->next = n2;
    display(n1);
    n1 = removeFromLast(n1,2);
    display(n1);
}