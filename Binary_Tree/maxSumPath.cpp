//Program to calculatet the max sum path from one node to another
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

int maxSumUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }
    int left = maxSumUtil(root->left, ans);
    int right = maxSumUtil(root->right, ans);

    int maxNode = max(max(root->data, root->data + left + right),
                       max(root->data + left, root->data + right));
    ans = max(ans, maxNode);
    int singlePath = max(max(root->data + left, root->data + right), root->data);
    return singlePath;
}

int maxSumPath(Node* root){
    int ans = INT_MIN;
    maxSumUtil(root, ans);
    return ans;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<maxSumPath(root)<<endl;

    return 0;
}