//Program to replace the node with the sum of its subtree. Time complexity = O(N), where N= no. of Nodes
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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void sumReplace(Node* root){
    if(root == NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);
    preOrder(root);
    cout<<endl;
    sumReplace(root);
    preOrder(root);
    
    return 0;
}