#include<iostream>
using namespace std;

int main(){

    // my method
    // int n,count;
    // cin>>n;
    // for(int i=n;i>=1;i--){
    //     count=1;
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //         count++;
    //     }
    //     cout<<endl;
    // }

    //another method
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}