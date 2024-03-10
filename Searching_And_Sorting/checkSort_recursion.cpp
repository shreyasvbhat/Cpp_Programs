//Program to check if entered array is sorted in ascending order  or not
#include<iostream>
using namespace std;

bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool restArray = sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restArray);
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
    if(sorted(arr,n)){
        cout<<"Array is in sorted in ascending order\n";
    }else cout<<"Array is not in sorted array\n";

    return 0;
}