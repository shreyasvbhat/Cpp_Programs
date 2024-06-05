//Program to calculate the sum of nodes in a binary tree
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

int sumOfNodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Sum of all the nodes in the binary serach tree = "<<sumOfNodes(root);
    return 0;
}