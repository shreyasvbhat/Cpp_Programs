//Program to calculate the diameter of the binary tree
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

//Calculating in O(N^2) time complexity (N for calulating height and N for calculating diameter)
int calHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(calHeight(root->left), calHeight(root->right))+1;
}

int calDiameter1(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight + rHeight +1;

    int lDiameter = calDiameter1(root->left);
    int rDiameter = calDiameter1(root->right);
    return max(currDiameter, max(lDiameter, rDiameter));
}

//Calculating the diameter in O(N) time complexity
//We pass the height as parameter where height is calculated within the diameter function. Hence the 
//recursive call will take O(N) only
int calDiameter2(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calDiameter2(root->left, &lh);
    int rDiameter = calDiameter2(root->right, &rh);
    int currDiameter = lh + rh + 1;

    *height = max(lh, rh)+1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int main(){
    int height = 0;
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);
    cout<<"O(N^2) time complexity"<<endl;
    cout<<"Diameter of the above tree = "<<calDiameter1(root)<<endl;
    cout<<"O(N) time complexity"<<endl;
    cout<<"Diameter of the above tree = "<<calDiameter2(root, &height)<<endl;
    
    return 0;
}