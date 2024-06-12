//Program to perform delete operation in a BST
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

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data > key){
        root->left = deleteInBST(root->left, key);
    }else if(root->data < key){
        root->right = deleteInBST(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
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
    struct Node* root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right = new Node(30);
    root->right->left = new Node(20);
    root->right->right = new Node(40);

    int x;
    cout<<"Enter the element to delete:\n";
    cin>>x;
    cout<<"Before deletion\n";
    inorder(root);
    root = deleteInBST(root , x);
    cout<<"\nAfter deletion\n";
    inorder(root);
    cout<<endl;

    return 0;
}