//Program to check if the entered sum exist in any of the pair in an array
#include<iostream>
using namespace std;

bool brutforce(int arr[], int n, int k){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool optimized(int arr[], int n, int k){
    int st = 0;
    int sum = 0;
    int en = n-1;
   while(st<en){
        sum = arr[st] + arr[en];
        if(sum == k){
            cout<<st<<" "<<en<<endl;
            return 1;
        }
        else if(sum>k){
            en = en-1;
        }
        else st = st+1;
    }
    return 0;

}

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the array in sorted order:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter a sum value:\n";
    cin>>k;
    cout<<"Brut force:\n";
    cout<<brutforce(a,n,k)<<endl;
    cout<<"Optimized approach:\n";
    cout<<optimized(a,n,k)<<endl;;
    return 0;
}