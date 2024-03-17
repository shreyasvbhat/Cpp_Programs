//Program to sort elements using selection sort

#include<iostream>
using namespace std;

int main(){
    int n,temp=0;
    cin>>n;

    int arr[n];

    //taking elements as array input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //selection sort alogithm
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    //outputing the sorted array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}