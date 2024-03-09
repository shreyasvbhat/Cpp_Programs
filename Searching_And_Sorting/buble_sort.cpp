//Program to sort elements using bubble sort

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //bubble sort algorithm

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j+1]<arr[j]){
                int temp = 0;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Elements after sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}