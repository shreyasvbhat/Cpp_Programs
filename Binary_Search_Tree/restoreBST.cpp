//Program to restore BST from given BT
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

void calPointer(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root == NULL){
        return;
    }
    calPointer(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }else{
            *last = root;
        } 
    }
    *prev = root;

    calPointer(root->right, first, mid, last, prev);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(Node* root){
    Node* first, *last, *mid, *prev;  
    first = NULL;
    last = NULL;
    mid = NULL;
    prev = NULL;

    calPointer(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data), &(last->data));
    } else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
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
    struct Node* root = new Node(50);
    root->left = new Node(80);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(30);

    inorder(root);
    restoreBST(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    
    return 0;
}