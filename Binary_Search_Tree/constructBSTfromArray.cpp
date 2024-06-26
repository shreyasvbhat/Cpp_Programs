//Program to construct a BST from an given array
#include<iostream>
#include<bits/stdc++.h>
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

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int n;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    vector<int> var(n);
    cout<<"Enter "<<n<<" elements of array:\n";
    for(int i=0; i<n; i++){
        cin>>var[i];
    }
    struct Node* root = NULL;
    root = insertBST(root, var[0]);;
    for(int i=1; i<n; i++){
        insertBST(root, var[i]);
    }
    cout<<"Inorder sequence of the constructed BST:\n";
    inorder(root);
    cout<<endl;

    return 0;
}