#include<iostream>

using namespace std;

int linearSearch(int ar[],int n, int k){
    for(int i=0;i<n;i++){
        if(ar[i] == k){
            return i+1;
        }
    }
    return -1;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    int index = linearSearch(arr,n,key);

    if(index == -1)
      cout<<"Element not found";
    else cout<<"Element found in "<<index<<" location";

    return 0;
}