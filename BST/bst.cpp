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

class container{
    public:
        node *head;
        node *tail;
        
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
    node *root = new node(arr[mid]);
    root->left = sortedArraytoBST(arr,start,mid-1); // start to mid -1 is left subtree
    root->right = sortedArraytoBST(arr,mid+1,end); // mid + 1 to end is right subtree
    return root;
}

int findClosest(node *root, int target){ // find number closest to target
    node *temp = root;
    int minDiff = INT_MAX;
    int closest;
    while(temp!=NULL){
        int currentDiff = abs(temp->data - target);
        if(currentDiff==0){
            return temp->data;
        }
        if(currentDiff<minDiff){
            minDiff = currentDiff;
            closest = temp->data;
        }
        if(temp->data < target){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return closest;
}

container convertToLinkedListInOrder(node *root){
    container c1,c2;
    if(root==NULL){
        c1.head=NULL;
        c1.tail=NULL;
        return c1;
    }
    if(root->left==NULL and root->right==NULL){
        c1.head = root;
        c1.tail = root;
        return c1;
    }
    if(root->left != NULL and root->right==NULL){
        c1 = convertToLinkedListInOrder(root->left);
        c1.tail->right = root;
        c1.tail = root;
        return c1;
    }
    if(root->left == NULL and root->right!=NULL){
        c1 = convertToLinkedListInOrder(root->right);
        c1.tail->right = root;
        c1.tail = root;
        return c1;
    }
    if(root->left!=NULL and root->right!=NULL){
        c1 = convertToLinkedListInOrder(root->left);
        c2 = convertToLinkedListInOrder(root->right);
        c1.tail->right = c2.head;
        c2.tail->right = root;
        c1.tail = root;
        return c1;
    }
    return c1;
}

container convertToLinkedListPreOrder(node *root){
        container c1,c2;
        if(root==NULL){
            c1.head=NULL;
            c1.tail=NULL;
            return c1;
        }
        if(root->left==NULL and root->right==NULL){
            c1.head = root;
            c1.tail = root;
            return c1;
        }
        if(root->left!=NULL and root->right==NULL){
            c1 = convertToLinkedListPreOrder(root->left);
            root->right = c1.head;
            c1.head = root;
        }
        else if(root->left==NULL and root->right!=NULL){
            c1 = convertToLinkedListPreOrder(root->right);
            root->right = c1.head;
            c1.head = root;
        }
        else{
            c1 = convertToLinkedListPreOrder(root->left);
            c2 = convertToLinkedListPreOrder(root->right);
            root->right = c1.head;
            c1.tail->right = c2.head;
            c1.head = root;
            c1.tail = c2.tail;
        }
        return c1;
}

// convert tree to linked list - don't make new linked list. Make the right pointers of tree into next of linked list
container convertToLinkedList(node *root){
     container c1,c2; // class to store head and tail

     if(root==NULL){
        c1.head=NULL;
        c1.tail=NULL;
        return c1;      
     }

     if(root->left==NULL and root->right==NULL){ // leaf node then the node itself is the head and tail
         c1.head = root;
         c1.tail = root;
         return c1;
     }

     if(root->left!=NULL and root->right==NULL){ // left->root
         c1 = convertToLinkedList(root->left);
         c1.tail->right = root;
         c1.tail = root;
     }
     
     else if(root->left==NULL and root->right!=NULL){ // root->right
         c1 = convertToLinkedList(root->right);
         root->right = c1.head;
         c1.head = root;
     }

     else{ // left->root->right
        c1 = convertToLinkedList(root->left);
        c2 = convertToLinkedList(root->right);
        c1.tail->right = root;
        root->right = c2.head;
        c1.tail=c2.tail; 
     }

     return c1;
 }

void dispLinkedList(container c){
    node *root = c.head;
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// o(n) method is to traverse through entire tree in inorder fashion and store it in an array, and then access.
node *inorderSuccessor(node *root, node *target){
    // if right subtree exists
    if(target->right!=NULL){
        node *temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }

    // if no right subtree
    node *temp = root;
    node *succ = NULL;
    while(temp!=NULL){
        if(temp->data > target->data){
            succ = temp;
            temp = temp->left;
        }
        else if(temp->data < target->data){
            temp = temp->right;
        }
        else{
            break;
        }
    }
    return succ;
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
    int a[] = {1,2,3,4,5,6,7};
    int n = 0;
    for(int x : a){
        root = insert(root,x); // form a bst
        n++;
    }
    // inorder(root);
    // cout<<"\n";
    // cout<<search(root,5)<<"\n";
    // vector<int> v = {1,2,3};
    // root = sortedArraytoBST(v, 0, v.size()-1);
    // preorder(root);
    // cout<<"\n";
    // cout<<findClosest(root,11)<<"\n";
    container c = convertToLinkedListInOrder(root);
    dispLinkedList(c);
}