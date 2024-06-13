//Program to check wheather given two BST are identical or not
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

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}

int main(){
    struct Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    struct Node* root2 = new Node(50);
    root2->left = new Node(30);
    root2->left->left = new Node(20);
    root2->left->right = new Node(40);
    root2->right = new Node(70);
    root2->right->left = new Node(60);
    root2->right->right = new Node(80);

    struct Node* root3 = new Node(50);
    root3->left = new Node(30);
    root3->left->left = new Node(20);
    root3->left->right = new Node(45);
    root3->right = new Node(70);
    root3->right->left = new Node(55);
    root3->right->right = new Node(80);

    if(isIdentical(root, root2)){
        cout<<"BST1 and BST2 are identical\n";
    }else{
        cout<<"BST1 and BST2 are not identical\n";
    }

    if(isIdentical(root, root3)){
        cout<<"BST1 and BST3 are identical\n";
    }else{
        cout<<"BST1 and BST3 are not identical\n";
    }

    return 0;
}