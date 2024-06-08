//Program to construct all the possible number of BST using concept of catalan numbers
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

vector<Node*> constructTree(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> leftTree = constructTree(start, i-1);
        vector<Node*> rightTree = constructTree(i+1, end);

        for(int j=0; j<leftTree.size(); j++){
            Node* left = leftTree[j];
            for(int k=0; k<rightTree.size(); k++){
                Node* right = rightTree[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cout<<"Enter the number of nodes:\n";
    cin>>n;
    vector<Node*> trees = constructTree(1,n);
    for(int i=0; i<trees.size(); i++){
        cout<<(i+1)<<" Tree: "<<endl;
        preorder(trees[i]);
        cout<<endl;
    } 

    return 0;
}