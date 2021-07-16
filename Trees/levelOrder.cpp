#include <bits/stdc++.h>
using namespace std;


class node{
    public:
        int data;
        node *left;
        node *right;
        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node *buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node *n = new node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void displayPreOrder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayLevelOrder(node *root){
    queue<node *> q; // type node because we have to access the children 
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *root = buildTree();
    displayPreOrder(root);
    cout<<"\n";
    displayLevelOrder(root);
}