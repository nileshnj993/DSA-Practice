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

void preOrder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int sumOfLeftLeaves(node* root) {
    if(root==NULL){ // if left or right child or root itself is null, return 0
        return 0;
    } 
    int sum = 0;
    if(root->left!=NULL && root->left->left == NULL && root->left->right==NULL){ // left leaves
        sum+=root->left->data;
    } 
    sum+=sumOfLeftLeaves(root->left);
    sum+=sumOfLeftLeaves(root->right);
    return sum;
}

int main(){
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    cout<<sumOfLeftLeaves(root)<<"\n";   
}
