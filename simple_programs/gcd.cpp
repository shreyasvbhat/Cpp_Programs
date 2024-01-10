//Program to find the GCD using euclid algorithm
#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main(){
    int x,y;
    cout<<"Enter two numbers:\n";
    cin>>x>>y;
    cout<<"Gcd of "<<x<<" and "<<y<<" is = "<<gcd(x,y);
    return 0;
}