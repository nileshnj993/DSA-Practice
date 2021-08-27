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

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void left(node *root, vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        v.push_back(root->data);
        left(root->left,v);
    }
    else if(root->right!=NULL){
        v.push_back(root->data);
        left(root->right,v);
    }
}

void leaf(node *root, vector<int> &v){
    if(root==NULL){
        return;
    }
    leaf(root->left,v);
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->data);
    }
    leaf(root->right,v);
}

void right(node *root, vector<int> &v){
    if(root==NULL){
        return;
    }

    if(root->right!=NULL){
        right(root->right,v);
        v.push_back(root->data);
    }

    else if(root->left!=NULL){
        right(root->left,v);
        v.push_back(root->data);
    }
   
}


vector<int> boundaryTree(node *root){
    vector<int> res;
    if(root==NULL){
        return res;
    }
    res.push_back(root->data);
    left(root->left,res);
    leaf(root,res);
    right(root->right,res);
    return res;
}

int main(){
    node *n1 = new node(20);
    node *n2 = new node(8);
    node *n3 = new node(22);
    node *n4 = new node(4);
    node *n5 = new node(12);
    node *n6 = new node(10);
    node *n7 = new node(14);
    node *n8 = new node(25);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;
    n3->right = n8;
    //inorder(n1);
    vector<int> res = boundaryTree(n1);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<"\n";
    cout<<res.size()<<" nodes in total!\n";
}