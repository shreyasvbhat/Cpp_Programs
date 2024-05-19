//Program to check wheather the tree is a height balanced binary tree
//Approach 1: Time complexity = O(N^2). N times for calulating height and N times for balance checking
//Approach 2: Time complexity = O(N). By calculating height inside N times for balance checking.
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

//Approach 1:
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(rh,lh)+1;
}

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)>1){
        return false;
    }else{
        return true;
    }
}

//Approach 2:
bool isBalanced(Node* root, int *height){
    if(root == NULL){
        return true;
    }
    int lh=0, rh=0;
    if(isBalanced(root->left, &lh) == false){
        return false;
    }
    if(isBalanced(root->right, &rh) == false){
        return false;
    }
    *height = max(lh, rh)+1;
    if(abs(rh-lh) > 1){
        return false;
    }else{
        return true;
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

    cout<<"Approach 1:\n";    
    if(isBalanced(root)){
        cout<<"It is a Balanced tree\n";
    }else{
        cout<<"It is not a Balanced tree\n";
    }
    int height = 0;
    cout<<"Approach 2:\n";    
    if(isBalanced(root, &height)){
        cout<<"It is a Balanced tree\n";
    }else{
        cout<<"It is not a Balanced tree\n";
    }
    return 0;
}