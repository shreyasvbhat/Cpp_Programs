//Program to search a node in a BST
//Time complexity in searching is O(log(N+1)), Where N is the number of nodes in BST

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* search(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(root->data > val){
        return search(root->left, val);
    }
    return search(root->right, val);
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right = new Node(30);
    root->right->left = new Node(20);
    root->right->right = new Node(40);
    int x;
    cout<<"Enter the element to search in BST:\n";
    cin>>x;
    if(search(root,x) != NULL){
        cout<<x<<" is present in BST\n";
    }else{
        cout<<x<<" is not present in BST\n";
    }
    inorder(root);
    cout<<endl;

    return 0;
}