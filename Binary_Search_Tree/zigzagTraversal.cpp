//Program to traverse a given BST in a zig zag manner
//Time complexity: O(n), where N is the number of nodes in BST
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

void zigzagTraversal(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp != NULL){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left != NULL){
                    nextLevel.push(temp->left);
                }
                if(temp->right != NULL){
                    nextLevel.push(temp->right);
                }
            }else{
                if(temp->right != NULL){
                    nextLevel.push(temp->right);
                }
                if(temp->left != NULL){
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main(){
    /*
            50
           /  \
          30   70
         /  \  /  \ 
        20  40 60  80
    */
    struct Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    zigzagTraversal(root);
    cout<<endl;

    return 0;
}