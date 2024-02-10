//Program to transpose a matrix
#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the order of matrix:\n";
    cin>>n>>m;
    cout<<"Enter the elements of the matrix:\n";
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int c[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[j][i] = a[i][j];
        }
    }
    cout<<"Result:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}