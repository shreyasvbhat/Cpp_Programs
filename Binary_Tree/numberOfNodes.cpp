//Program to count the number of nodes in a Binary Tree
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

int numberOfNodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Total number of nodes = "<<numberOfNodes(root);
    return 0;
}
