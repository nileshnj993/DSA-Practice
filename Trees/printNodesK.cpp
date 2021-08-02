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

vector<int> distanceK(node *root, int k){
    vector<int> result;
    int distance = 0;
    if(k==0){
        result.push_back(root->data);
        return result;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            distance++;
            q.pop();
            if(distance==k){
                while(q.front()!=NULL && !q.empty()){
                    result.push_back(q.front()->data);
                    q.pop();
            }
            break;
         }
          
            if(!q.empty()){
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

int main(){
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    int k;
    cin>>k;
    vector<int> result = distanceK(root,k);
    for(auto i: result){
        cout<<i<< " ";
    }   
    cout<<"\n";
}
