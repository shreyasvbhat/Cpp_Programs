//Program to perfrom DNF sort
#include<iostream>
using namespace std;

void dnfSort(int arr[], int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while (mid<=high){
        if(arr[mid]==0){
            int temp = arr[low];
            arr[low] =arr[mid];
            arr[mid] =temp;
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else {
            int temp = arr[mid];
            arr[mid] =arr[high];
            arr[high] = temp;
            high--;
        }
    }
        
}

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dnfSort(arr,n);
    cout<<"After sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;    
}