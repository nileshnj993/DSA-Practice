#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *right;
        node *left;
        node(int x){
            data = x;
            right = NULL;
            left = NULL;
        }
};

void printCorner(node *root)
{
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
                cout<<q.front()->data<<" "; // left mpst
            }
        }
        else{
            q.pop();
            if(q.front()==NULL){ // right most
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
           
        }
    }

}

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
    printCorner(n1);
    cout<<"\n";
}