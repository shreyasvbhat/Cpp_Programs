//Program to display all subsets using bit manipulation
#include<iostream>
using namespace std;

int subset(int arr[], int n){
    for(int i=0;i< (1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int arr[20],n;
    cout<<"Enter the limit:\n";
    cin>>n;
    cout<<"Enter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subset(arr,n);
    return 0;
}