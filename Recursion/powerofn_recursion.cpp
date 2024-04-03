//Program to calculate n power p using recursion
#include<iostream>
using namespace std;

int power(int n, int p){
    if(p==0){
        return 1;
    }
    int prevPower = power(n, p-1);
    return (n*prevPower);
}

int main(){
    int n,p;
    cout<<"Enter the base element:\n";
    cin>>n;
    cout<<"Enter the power element:\n";
    cin>>p;
    cout<<n<<" power "<<p<<" is = "<<power(n,p);
    return 0;
}