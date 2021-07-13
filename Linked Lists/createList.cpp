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

void insertAtHead(node * &head, int data){
    if(head==NULL){ // empty list
        head = new node(data);
    }
    else{ // elements already there in list
        node *n = new node(data);
        n->next = head;
        head = n;
    }
}

void insertAtEnd(node *&head, int data){
    if(head==NULL){
        head = new node(data);
    }
    else{
        node *n = head;
        while(n->next != NULL){
            n = n->next;
        }
        node *tail = new node(data);
        n->next = tail;
    }
}

void insertInMiddle(node *&head, int data, int pos){ // pos is index of new element
    if(pos==0){
        insertAtHead(head,data);
    }
    else{
        node *n = head;
        int i = 0;
        while(i<pos-1){
            n = n->next;
            i++;
        }
        node *ele = new node(data);
        ele->next = n->next;
        n->next = ele;
    }
}

void searchNode(node *head, int data){
    int found = 0;
    int pos = 0;
    while(head!=NULL){
        if(head->data == data){
            cout<<"Element "<<data<<" found at position "<<pos<<"\n";
            found = 1;
            break;
        }
        else{
            head = head->next;
            pos++;
        }
    }
    if(found==0){
        cout<<"Element not found!\n";
    }
}

void deleteAtHead(node *&head){
    if(head==NULL){
        cout<<"Empty list!\n";
    }
    else{
        node *n = head;
        head = head->next;
        delete n;
    }
}

void deleteInMiddle(node *&head, int pos){
    if(pos==0){
        deleteAtHead(head);
    }
    else{
        int i = 0;
        node *n = head;
        while(i<pos-1){
            n = n->next;
            i++;
        }
        node *temp = n->next;
        n->next = temp->next;
        delete temp;
    }
}

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

int main(){
    
    node *n = NULL;
    int choice=0;
    bool loop = true;
    while(loop){
        cout<<"1. Insert at head"<<" "<<"2. Insert at end"<<" "<<"3. Insert in middle"<<" "<<"4. Delete at head"<<" "<<"5. Delete in middle"<<" "<<"6. Display"<<" "<<"7. Search"<<" "<<"8. Exit\n";
        cin>>choice;
    
        if(choice==1){
            cout<<"Enter data:";
            int data;
            cin>>data;
            insertAtHead(n,data);
           
        }

        else if(choice==2){
            cout<<"Enter data:";
            int data;
            cin>>data;
            insertAtEnd(n,data);
        }

        else if(choice==3){
            cout<<"Enter data:";
            int data;
            cin>>data;
            int pos;
            cout<<"Enter position:";
            cin>>pos;
            insertInMiddle(n,data,pos);
        }

        else if(choice==4){
            deleteAtHead(n);
        }

        else if(choice==5){
            int pos;
            cout<<"Enter position:";
            cin>>pos;
            deleteInMiddle(n,pos);
        }

        else if(choice==6){
            display(n);
        }
        
        else if(choice==7){
            cout<<"Enter element to be searched for:";
            int ele;
            cin>>ele;
            searchNode(n,ele);
        }


        else{
            loop = false;
        }
    }
    // insertAtHead(n,4);
    // insertAtHead(n,2);
    // insertAtHead(n,3);
    // insertAtEnd(n,5);
    // insertInMiddle(n, 7, 3); // this can handle insert at end also.
    // display(n);
    // cout<<"\n";
    // searchNode(n,4);
    // searchNode(n,121);
    // deleteAtHead(n);
    // display(n);
    // cout<<"\n";
    // deleteInMiddle(n,3);
    // display(n);
    // cout<<"\n";
}