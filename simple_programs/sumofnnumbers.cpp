#include<iostream>
using namespace std;

float sum(int n){
    int sum=0;
    sum = (n*(n+1))/2;
    return sum;
}

int main(){
    int n;
    cin>>n;
    float result = sum(n);
    cout<<result<<endl;

    return 0;
}