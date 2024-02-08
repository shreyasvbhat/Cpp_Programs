//Program to find an element in matrix
#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the order:\n";
    cin>>n>>m;
    int a[n][m];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int target;
    cout<<"Enter the searching element:\n";
    cin>>target;
    int p =-1,q;
    int r=0;
    int c= n-1;
    while(r<n && c>=0 ){
        if(a[r][c]== target){
            p = r+1;
            q = c+1;
            break;
        }
        else if(a[r][c]>target){
            c--;
        }else r++;
    }
    if(p == -1){
        cout<<"Element not found\n";
    }else {
        cout<<"Elements found in coordinates ("<<p<<","<<q<<")"<<endl;
    }
    return 0;
}