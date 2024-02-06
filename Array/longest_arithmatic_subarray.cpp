//Program to find the longest subarray which is in AP
#include<iostream>
using namespace std;

// int max(int n, int m){
//     if(m>n){
//         return m;
//     }
//     else return n;
// }

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int curr = 2;
    int pd = arr[1] - arr[0];
    int j=2,ans = 2;
    while(j<n){
        if(pd == arr[j]-arr[j-1]){
            curr++;
        }
        else {
            pd = arr[j] - arr[j-1];
            curr = 2;
        }
        ans = max(ans,curr);
        j++;
    }
    cout<<ans<<endl;
    return 0;
}