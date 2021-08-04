// vertical print means on the same x coordinate. root is at 0. Left child is -1 and right child is +1.

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

// in postorder we go left -> right -> root

void preOrder(node *root){ // ( root -> left -> right)
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void traverseTree(node *root, int d, map<int,vector<int>>&m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
}

void verticalOrderPrint(node *root){
    map<int,vector<int>> m; // map instead of unordered map so we can print from left to right
    int d = 0;
    traverseTree(root,d,m);
    for(auto p : m){
        int key = p.first;
        vector<int> line = p.second;
        for(auto data:line){
            cout<<data<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    node *root = buildTree();
    // preOrder(root);
    cout<<"\n";

    verticalOrderPrint(root);
}
