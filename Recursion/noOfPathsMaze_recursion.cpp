//Program to find the total number of paths in a maze if you could only more sideways or downways
#include<iostream>
using namespace std;

int noOfMaze(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }

    return noOfMaze(n,i+1,j) + noOfMaze(n,i,j+1);
}

int main(){
    int n;
    cout<<"Enter the size of the maze:\n";
    cin>>n;
    cout<<"Number of paths = "<<noOfMaze(n,0,0);
}