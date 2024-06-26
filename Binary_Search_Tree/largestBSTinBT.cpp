//Program to print the size of the largest BST in a BT
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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root){
    if(root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);

    Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min , min(rightInfo.min, root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    return curr;
}

int main(){
    struct Node* root = new Node(20);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout<<"Size of largest BST: "<<largestBST(root).ans<<endl;

    return 0;
}