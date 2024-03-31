//Program to find the first and last occurance of a number using recursion
#include<iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int k){

    if(n==i){
        return -1;
    }

    if(arr[i]==k){
        return i;
    }
    return firstocc(arr,n,i+1,k);
}

int lastocc(int arr[], int n, int i, int k){
    if(n==i){
        return -1;
    }
    int restArray = lastocc(arr,n,i+1,k);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==k){
        return i;
    }
    return -1;
    
}

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the searching element\n";
    int k;
    cin>>k;
    cout<<firstocc(arr,n,0,k)<<endl;
    cout<<lastocc(arr,n,0,k)<<endl;

    return 0;
}