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

node *levelOrderBuild(){ // if input given in level order
    int data;
    cin>>data;
    node *root = new node(data);
    queue<node *> q;
    q.push(root);

    while(!q.empty()){
        node *current = q.front();
        q.pop();
        int child1, child2;
        cin>>child1>>child2;
        if(child1!=-1){
            current->left = new node(child1);
            q.push(current->left);
        }
        if(child2!=-1){
            current->right = new node(child2);
            q.push(current->right);
        }
    }
    return root;

}

vector <int> preorderIterative(node* root)
{
  vector<int> result;
  stack<node *> nodes;
  nodes.push(root);
  while(!nodes.empty()){
      node *temp = nodes.top();
      nodes.pop();
      if(temp->right){ // pushing right first coz we need left on top
          nodes.push(temp->right);
      }
      if(temp->left){
          nodes.push(temp->left);
      }
      result.push_back(temp->data);
  }
  return result;
}

void displayPreOrder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayLevelOrder(node *root){
    queue<node *> q; // type node because we have to access the children 
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    node *root = levelOrderBuild();
    displayPreOrder(root);
    cout<<"\n";
    vector<int> result = preorderIterative(root);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<"\n";
    displayLevelOrder(root);
}