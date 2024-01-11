//Program to find the no. of divisible by 2 numbers
#include<iostream>
using namespace std;

int divisible(int n, int a, int b){
    int n1=n/a;
    int n2 = n/b;
    int n3 = n/(a*b);
    return (n1+n2-n3);
}

int main(){
    int a,b,c;
    cout<<"Enter the number:\n";
    cin>>a;
    cout<<"Enter two number to check divisibility:\n";
    cin>>b>>c;
    cout<<a<<" is divisible by "<<divisible(a,b,c)<<" elements\n";
    return 0;
}