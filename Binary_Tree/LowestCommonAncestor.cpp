//Program to find the Lowest Common Ancestor in a Binary Tree
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

//method 1:

bool getPath(Node* root, int k, vector<int>& path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data == k){
        return true;
    }

    if(getPath(root->left, k, path) || getPath(root->right, k, path)){
        return true;
    }
    path.pop_back();

    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pc;
    for(pc = 0; pc< path1.size() && path2.size(); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
}

//method 2
Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLca = LCA2(root->left, n1, n2);
    Node* rightLca = LCA2(root->right, n1, n2);

    if(leftLca && rightLca){
        return root;
    }
    if(leftLca != NULL){
        return leftLca;
    }
    return rightLca;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    int lca = LCA(root, 8, 7);
    Node* LcaNode = LCA2(root, 8, 7);
    if(lca != -1){
        cout<<"LCA: "<<lca<<endl;
    }else{
        cout<<"LCA doesn't exist"<<endl;
    }

    if(LcaNode != NULL){
        cout<<"LCA: "<<LcaNode->data<<endl;
    }else{
        cout<<"LCA doesn't exist"<<endl;
    }

    return 0;
}