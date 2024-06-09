//Program to check if the given Tree is a BST or not
//Time complexity: O(N), where N is the number of nodes in the Tree
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

bool isBST(Node* root, Node* min = NULL, Node* max = NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    bool leftBST = isBST(root->left, min, root);
    bool rightBST = isBST(root->right, root, max);

    return leftBST && rightBST;
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right = new Node(30);
    root->right->left = new Node(20);
    root->right->right = new Node(40);

    struct Node* root2 = new Node(10);
    root2->left = new Node(7);
    root2->left->left = new Node(45);
    root2->left->right = new Node(9);
    root2->right = new Node(2);
    root2->right->left = new Node(20);
    root2->right->right = new Node(40);

    if(isBST(root, NULL, NULL)){
        cout<<"It is a BST\n";
    }else{
        cout<<"It is not a BST\n";
    }
    
    if(isBST(root2, NULL, NULL)){
        cout<<"It is a BST\n";
    }else{
        cout<<"It is not a BST\n";
    }

    return 0;
}