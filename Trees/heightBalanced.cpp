// a height balanced tree is one in which all left and right subtrees are balanced, and max difference between heights of left and right subtree is 1
// eg - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

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

pair<int, bool> heightBalanced(node *root){ // int represents height of subtree and the bool signifies it the subtree is balanced
    pair<int,bool> p;
    if(root==NULL){
        p.first = 0; // height
        p.second = true; // null trees are balanced
        return p;
    } 
    pair<int,bool> Left = heightBalanced(root->left);  
    pair<int,bool> Right = heightBalanced(root->right); 
    p.first = 1 + max(Left.first, Right.first);
    if(abs(Left.first - Right.first)<=1 && Left.second==true && Right.second==true){
        p.second = true;
    }
    else{
        p.second = false;
    }
    return p;

}

int main(){
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    cout<<heightBalanced(root).second<<"\n";   
}
