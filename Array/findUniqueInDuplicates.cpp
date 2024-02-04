//Program to find the unique element in a list of elements 

#include<iostream>
using namespace std;

//direct method not yet finished
// int main(){
//     int n,arr[25],temp,count=0;
//     cout<<"Enter the limit:\n";
//     cin>>n;
//     cout<<"Enter the elements:\n";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(arr[i]>arr[j]){
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     temp = arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i] != temp ){
//             temp = arr[i];
//         }else count++;
//     }
//     cout<<temp<<endl;
// }

int setBit(int n, int pos){
    return ((n & (1<<pos) )!=0);
}

void unique(int arr[],int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    }
    int temp=xorsum;
    int setbit = 0;
    int pos=0;
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i], pos-1)){
            newxor = newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(temp^newxor)<<endl;
}

int main(){
    int n,arr[25];
    cout<<"Enter the limit:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unique(arr,n);
    return 0;
}
