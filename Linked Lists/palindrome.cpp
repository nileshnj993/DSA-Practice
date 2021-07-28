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

void display(node *head){ // passing by dataue not reference
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
  
  
bool isPalindrome(node* head) {
       
        bool palindrome = true;
        stack<int> st;
        node *i = head;
        while(i!=NULL){
            st.push(i->data);
            i = i->next;
        }
        i = head;
        while(i!=NULL){
            if(i->data != st.top()){
                palindrome = false;
                break;
            }
            i = i->next;
            st.pop();
        }
        return palindrome;
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
    node *n2 = new node(1);
    node *n3 = new node(2);
    node *n4 = new node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    display(n1);
    bool result = isPalindrome(n1);
    cout<<result<<"\n";
}