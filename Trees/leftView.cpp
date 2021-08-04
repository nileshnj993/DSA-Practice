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


vector<int> leftView(node * root){
    vector<int> result;
    queue<node *>q;
    result.push_back(root->data);
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            q.pop();
            if(!q.empty()){
                result.push_back(q.front()->data);
                q.push(NULL);
            }
        }
        else{
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return result;
}

vector<int> rightView(node *root){
      vector<int> result;
    queue<node *>q;
    result.push_back(root->data);
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            q.pop();
            if(!q.empty()){ 
                result.push_back(q.front()->data);
                q.push(NULL);
            }
        }
        else{
            q.pop();
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
            
        }
    }
    return result;
}

int main(){
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    vector<int> result = leftView(root);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
    result = rightView(root);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
      
}
