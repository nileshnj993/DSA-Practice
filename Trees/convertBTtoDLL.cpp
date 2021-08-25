#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
        node(int x){
            data = x;
            left = NULL;
            right = NULL;            
        }
};


class binaryTree{
    public:
        node *prev=NULL;
        node *head=NULL;

        void convertToDLL(node *root){
            if(root==NULL){
                return;
            }

            convertToDLL(root->left); // just change the order of recursive calls depending on order asked.
    
            if(prev==NULL){
                head = root;
                prev = root;
            }
            else{
                root->left = prev;
                prev->right = root;
                prev = root;
            }
    
            convertToDLL(root->right);
        }
};



int main(){
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    node *n7 = new node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    binaryTree b;
    b.convertToDLL(n1);
    node *temp = b.head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->right;
    // }
    temp = temp->right;
    cout<<temp->left->data;
}