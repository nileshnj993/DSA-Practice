// given a bt, replace every node with the sum of all its descendants. Leave leaf nodes as it is.

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

int replaceWithSum(node *&root){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right==NULL){
        return root->data;
    }
    int leftSum = 0;
    int rightSum = 0;
    int temp = root->data;
    if(root->left){
        leftSum+=replaceWithSum(root->left);
    }
    if(root->right){
        rightSum+=replaceWithSum(root->right);
    }
    root->data = leftSum+rightSum;
    return root->data + temp;
}

int main(){
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    replaceWithSum(root);
    preOrder(root);
}