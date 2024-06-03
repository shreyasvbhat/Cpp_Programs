//Program to calculate the shortest distance between 2 nodes in a binary tree
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

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDistance(Node* root, int k, int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }

    int left = findDistance(root->left, k, dist+1);
    if(left != -1){
        return left;
    }
    return findDistance(root->right, k, dist+1);
}

int distanceBtwNodes(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);
    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1+d2;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);

    cout<<"Distance between 8 and 5 is = "<<distanceBtwNodes(root, 8, 5)<<endl;

    return 0;
}