//Program to find the sum of a subarray

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    //Sum of subarray logic
    for(int i=0; i<n; i++){
        int curr =0;
        for(int j= i; j<n;j++){
            curr += arr[j];
            cout<<curr<<" ";
        }
    }
    return 0;
}