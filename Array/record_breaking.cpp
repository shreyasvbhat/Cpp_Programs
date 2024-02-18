//Program to find the number of numbers which is greater than all previous numbers and also greater than
// the following number too in an array

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;

    int arr[n+1];
    int mx =-1;
    int ans = 0;
    arr[n] = -1;

    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }

    for(int i=0; i<n;i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            ans ++;
        }
        mx = max(mx, arr[i]);
    }

    cout<<"Record breaking numbers:\n";
    cout<<ans<<endl;
    return 0;
}