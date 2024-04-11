//Program to find all possible ways of tiling
#include<iostream>
using namespace std;

int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return tilingWays(n-1)+tilingWays(n-2);
}

int main(){
    int n;
    cout<<"Enter the n value in 2xn matrix:\n";
    cin>>n;
    cout<<"Possible ways : "<<tilingWays(n)<<endl;
    return 0;
}