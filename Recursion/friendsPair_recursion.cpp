//program to pair friends using recursion
#include<iostream>
using namespace std;

int friends(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }

    return (friends(n-1) + friends(n-2)*(n-1));
}

int main(){
    int n;
    cout<<"Enter the number of friends:\n";
    cin>>n;
    cout<<"Number of possible ways of pairing or single is: "<<friends(n)<<endl;
    return 0;
}