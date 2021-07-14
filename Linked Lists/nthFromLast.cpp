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

int fromLast(node *head, int n){

    
    //  SLOW SOLUTION
    //  node *temp = head;
    //  int count = 0;
    //  while(temp!=NULL){
    //      count++;
    //      temp = temp->next;
    //  }
    
    //  if(n>count){
    //      return -1;
    //  }
    //  int pos = count-n+1;
    //  count = 0;
    //  while(count<pos-1){
    //      head = head->next;
    //      count++;
    //  }
    //  return head->data;

    // FAST SOLUTION
    node *i = head; // slow pointer
    node *j = head; // fast pointer
    int count = 0;
    while(count<n){
        count++;
        j=j->next;
    }
    while(j!=NULL){
        i=i->next;
        j=j->next;
    }
    return i->data;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout<<fromLast(n1,2)<<"\n";
}