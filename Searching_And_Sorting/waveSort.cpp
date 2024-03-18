//Program to implement wave sort technique
//Time complexity is O(N)
#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[], int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1])
         swap(arr,i,i-1);
        
        if(arr[i]>arr[i+1]  &&  i<=n-2){
            swap(arr,i,i+1);
        }
    }
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
    waveSort(arr,n);
    cout<<"After waveSort:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}