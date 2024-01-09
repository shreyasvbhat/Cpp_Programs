#include<iostream>
using namespace std;

void fibonacci(int n){
    int t1=0;
    int t2=1;
    int t3;
    for(int i=1;i<=n;i++){
        cout<<t1<<" ";
        t3=t1+t2;
        t1=t2;
        t2=t3;
    }
}

int main(){
    int n;
    cin>>n;
    fibonacci(n);
    return 0;
}