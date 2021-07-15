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

node *midPoint(node *head){
    node *slow = head;
    node *fast = head->next;
    while(fast!=NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *a, node *b){
    node *res;
    node *i = a;
    node *j = b;
    if(i->data < j->data){
        res = i;
        i = i->next;
    }
    else{
        res = j;
        j = j->next;
    }
    node *temp;
    temp = res;
    while(i!=NULL && j!=NULL){
        if(i->data < j->data){
            temp->next = i;
            i = i->next;
            temp = temp->next;
        }
        else{
            temp->next = j;
            j = j->next;
            temp = temp->next;
        }
    }
    while(i!=NULL){
        temp->next = i;
        i = i->next;
        temp = temp->next;
    }
    while(j!=NULL){
        temp->next = j;
        j = j->next;
        temp = temp->next;
    }
    return res;
}

node* mergeSort(node *head){
    if(head==NULL || head->next==NULL){ // start>=end
        return head;
    }
    node *mid = midPoint(head);
    node *i = head;
    node *j = mid->next;
    mid->next = NULL; // break the list into two
    i = mergeSort(i); // sort first half
    j = mergeSort(j); // sort second half

    return merge(i,j);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *n1 = new node(1);
    node *n2 = new node(3);
    node *n3 = new node(1);
    node *n4 = new node(8);
    node *n5 = new node(6);
    node *n6 = new node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    display(n1);
    node *res = mergeSort(n1);
    display(res);
}