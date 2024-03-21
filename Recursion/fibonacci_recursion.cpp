//Program to find  nth fibonacci numbers
#include<iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return (fib(n-1)+fib(n-2));
}

int main(){
    int n;
    cout<<"Enter a number:\n";
    cin>>n;
    cout<<n<<"th Fibonacci elements is:\n";
    cout<<fib(n);
    return 0;
}