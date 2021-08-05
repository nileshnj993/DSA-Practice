// binary tree where every left and right subtree is also a bst and all left subtree nodes have values <= root and right subtree have > node
// in order traversal of bst will always be sorted
// reduces time complexity to search for an element as compared to a BT
// BT - O(N), BST - O(H)
// a tree has height between log(n)[perfectly balanced] and n[skewed]
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

node *insert(node *root, int x){
    if(root==NULL){ // base case
        return new node(x);
    }
    if(x<root->data){
        root->left = insert(root->left,x); // go to the left subtree and insert x
    }
    else{
        root->right = insert(root->right,x);
    }
    return root;
}

node *sortedArraytoBST(vector<int> arr, int start, int end){ // we can't do normal insert as it will form a skewed tree
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2; // middle element is always root
    node *temp = new node(arr[mid]);
    temp->left = sortedArraytoBST(arr,start,mid-1); // start to mid -1 is left subtree
    temp->right = sortedArraytoBST(arr,mid+1,end); // mid + 1 to end is right subtree
    return temp;
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(node *root, int key){
    if(root==NULL){
        return false;
    }
    bool present = false;
    node *temp = root;
    while(temp!=NULL){
        if(temp->data == key){
            present = true;
            break;
        }
        if(temp->data < key){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return present;
}

void preorder(node *root){
    if(root==NULL){
        cout<<-1<<" ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    node *root = NULL;
    int a[] = {8,3,10,1,6,14,4,7,13};
    int n = 0;
    for(int x : a){
        root = insert(root,x); // form a bst
        n++;
    }
    inorder(root);
    cout<<"\n";
    cout<<search(root,5)<<"\n";
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    root = sortedArraytoBST(v, 0, v.size()-1);
    preorder(root);
    cout<<"\n";
}