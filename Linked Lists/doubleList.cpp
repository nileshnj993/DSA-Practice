#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;

        node(){
            data=0;
            next = NULL;
            prev = NULL;
        }

        node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

void insertAtHead(node* &head, int data){
    if(head==NULL){
        node *temp = new node(data);
        head = temp;
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtEnd(node* &head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    node *i = head;
    while(i->next!=NULL){
        i = i->next;
    }
    i->next = temp;
    temp->prev = i;
}

void insertInMiddle(node *&head, int data, int pos){
    int count = 0;
    if(pos==0){
        insertAtHead(head,data);
        return;
    }
    node *temp = new node(data);
    node *i = head;
    while(count<pos-1){
        count++;
        i = i->next;
    }
    if(i->next==NULL){
        insertAtEnd(head,data);
        return;
    }
    temp->next = i->next;
    temp->prev = i;
    i->next->prev = temp;
    i->next = temp;
}

void deleteAtHead(node *&head){
    if(head==NULL){
        cout<<"Empty List!\n";
        return;
    }
    if(head->next == NULL){
        node *temp = head;
        head = NULL;
        return;
    }
    
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteInMiddle(node *&head, int pos){
    if(head==NULL){
        cout<<"Empty List!\n";
        return;
    }
    if(pos==0){
        deleteAtHead(head);
    }
    int count = 0;
    node *temp;
    node *i = head;
    while(count<pos-1){
        count++;
        i = i->next;
    }
    temp = i->next;
    i->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = i;
    }
    delete temp;
}

void reversePrint(node* &head){
    node *i = head;
    while(i->next!=NULL){
        i=i->next;
    }
    while(i!=NULL){
        cout<<i->data<<" ";
        i = i->prev;
    }
    cout<<"\n";
}

void display(node *head){
    if(head==NULL){
        cout<<"Empty list!\n";
        return;
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
    int choice;
    while(true){
        cout<<"1. Insert at head"<<" "<<"2. Insert at end"<<" "<<"3. Insert in middle"<<" "<<"4. Delete at head"<<" "<<"5. Delete in middle"<<" "<<"6. Display"<<" "<<"7. Reverse Display"<<" "<<"8. Exit\n";
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
            reversePrint(n);
        }
        
        else{
            break;
        }
    }
}
    