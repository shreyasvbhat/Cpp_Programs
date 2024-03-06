//Program to find the unique element in an array where rest are in triples
#include<iostream>
using namespace std;
int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int unique(int arr[], int n){
    int result =0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBit(result,i);
        }
    }
    return result;
}

int main(){
    int n,arr[25];
    cout<<"Enter the limit:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<unique(arr,n);
    return 0;
}