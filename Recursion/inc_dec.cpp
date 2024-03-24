//Program to display n numbers in both ascending and descending order
#include<iostream>
using namespace std;

void inc(int n){
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}

void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}

int main(){
    int n;
    cout<<"Enter a number:\n";
    cin>>n;
    inc(n);
    dec(n);
    return 0;
}