#include<iostream>

using namespace std;

int binarySearch(int a[], int n, int k){
    int mid=0,beg=0,end=n;
    while(beg<=end){
        mid = (beg+end)/2;
        if(a[mid]==k){
            return mid+1;
        }
        else if(k>a[mid])
                beg = mid+1;
            else end = mid-1;
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter the limit\n";
    cin>>n;

    cout<<"Enter the array elements\n";

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Searching element\n";
    cin>>key;

    int index = binarySearch(arr, n-1, key);

    if(index==-1)
      cout<<"Element not found\n";
    else cout<<"Element found in "<<index<<" location";

    return 0;

}