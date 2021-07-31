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
    if(root==NULL){ // leaf node
        return 0;
    }
    int h1 = height(root->left); // height of left subtree
    int h2 = height(root->right); // height of right subtree
    return 1 + max(h1,h2); // max of left and right subtree + root node
}

int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int d1,d2,d3;
    d1 = height(root->left) + height(root->right);
    d2 = diameter(root->left);
    d3 = diameter(root->right);
    return max(d1,max(d2,d3));
}

class HDPair{
    public:
        int diameter;
        int height;
};

HDPair optDiameter(node *root){
    HDPair p;
    if(root==NULL){
        p.diameter=0;
        p.height=0;
        return p;
    }
    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);
    p.height = max(Left.height, Right.height) + 1;
    int d1 = Left.height + Right.height;
    int d2 = Left.diameter;
    int d3 = Right.diameter;
    p.diameter = max(d1,max(d2,d3));
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *root = buildTree();
    displayPreOrder(root);
    cout<<"\n";
    cout<<diameter(root)<<"\n";
    cout<<optDiameter(root).diameter<<"\n";
}