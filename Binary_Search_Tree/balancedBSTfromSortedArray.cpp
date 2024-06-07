//PRogram to build a balanced BST from given a sorted array
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

void preorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

Node* buildBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildBST(arr, start, mid-1);
    root->right = buildBST(arr, mid+1, end);
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
    Node* root = buildBST(arr, 0, n-1);
    cout<<"Preorder sequence of the constructed BST:\n";
    preorderPrint(root);

    return 0;
}