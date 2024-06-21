//Program to find the peak element in an array using binary search method
#include<iostream>
using namespace std;

int findPeakElement(int arr[], int low, int high, int n){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])){
        return mid;
    }
    else if(mid>0 && arr[mid-1] > arr[mid]){
        return findPeakElement(arr, low, mid-1, n);
    }else{
        return findPeakElement(arr, mid+1, high, n);
    }
}

int main(){
    int n;
    cout<<"Enter the limit of the array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int peak = findPeakElement(arr, 0, n-1, n);
    cout<<"First peak element in the array is at index = "<<peak<<endl;

    return 0;
}