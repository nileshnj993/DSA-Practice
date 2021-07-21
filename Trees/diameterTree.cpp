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

int height(node *root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);
}

int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1, max(d2,d3));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *root = buildTree();
    displayPreOrder(root);
    cout<<"\n";
    cout<<diameter(root)<<"\n";
}