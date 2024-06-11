//Program to construct BST from preorder sequence
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

void preorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

Node* buildPreorder(int preorder[], int* preIdx, int key, int min, int max, int n){
    if(*preIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preIdx = *preIdx + 1;
        if(*preIdx < n){
            root->left = buildPreorder(preorder, preIdx, preorder[*preIdx], min, key, n);
        }
        if(*preIdx < n){
            root->right = buildPreorder(preorder, preIdx, preorder[*preIdx], key, max, n);
        }
    }
    return root;
}

int main(){
    int n;
    cout<<"Enter the array size:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the preorder sequence:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int preIdx = 0;
    Node* root = buildPreorder(arr, &preIdx, arr[0], INT_MIN, INT_MAX, n);
    cout<<"Preorder sequence of the constructed BST:\n";
    preorderPrint(root);

    return 0;
}