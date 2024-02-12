//Program to find the max number in the array range

#include<iostream>
using namespace std;

int max(int n, int m){
    if(m>n){
        return m;
    }
    else return n;
}

int main(){
    int n,maxNo = -999999 ;
    cout<<"Enter the  limit:\n";
    cin>>n;
    int arr[n];

    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        maxNo = max(maxNo,arr[i]);
        cout<<maxNo<<endl;
    }

    cout<<maxNo<<endl;
}