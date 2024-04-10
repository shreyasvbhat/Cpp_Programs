//Program to find the sum of n numbers using recursion
#include<iostream>
using namespace std;

int sum(int n){
    if(n==0)
    {
        return 0;
    }
    int prevSum = sum(n-1);
    return n+prevSum;
}

int main(){
    int n;
    cout<<"Enter a number:\n";
    cin>>n;
    cout<<"Sum till entered number = "<<sum(n)<<endl;
    return 0;
}