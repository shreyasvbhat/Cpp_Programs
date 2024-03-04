#include<iostream>
using namespace std;

int powerof2(int x){
    return (x && !(x & x-1));
}

int main(){
    int n;
    cout<<"Enter a number:\n";
    cin>>n;
    cout<<powerof2(n)<<endl;
    return 0;
}