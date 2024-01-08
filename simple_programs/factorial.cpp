#include<iostream>
using namespace std;

void fact(int n){
    int sum=1;
    for(int i=2;i<=n;i++){
        sum = sum*i;
    }
    cout<<sum<<endl;
}

int main(){
    int n;
    cin>>n;
    fact(n);

    return 0;
}