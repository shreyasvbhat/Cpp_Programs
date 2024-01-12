#include<iostream>
using namespace std;

int fact(int n){
    int sum=1;
    for(int i=2;i<=n;i++){
        sum = sum*i;
    }
    return sum;
}

int main(){
    int n,r,value;
    cin>>n>>r;
    int x= n-r;
    value = fact(n)/(fact(x)*fact(r));

    cout<<value<<endl;

    return 0;
}