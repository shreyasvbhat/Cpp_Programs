//Program to find the largst minimum distance in an array
#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int mid, int n, int k){
    int pos = arr[0];
    int element = 1;
    for(int i=1; i<n; i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            element++;
            if(element == k){
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k){
    sort(arr, arr+n);
    int ans = -1;
    int left = arr[0], right = arr[n-1];

    while(left < right){
        int mid = (left + right)/2;
        if(isFeasible(arr, mid, n ,k)){
            ans = max(ans, mid);
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the array limit:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the number of elements needed in the pair:\n";
    cin>>k;
    cout<<"Largest minimum distance = "<<largestMinDistance(arr,n,k)<<endl;

    return 0;
}