//Program to find factorial using recursion
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    //int prevfact = factorial(n-1);
    return (n*factorial(n-1));
}

int main(){
    int n;
    cout<<"Enter a number:\n";
    cin>>n;
    cout<<"Factorial = "<<factorial(n);
    return 0;
}