//Program to print catalan numbers
#include<iostream>
using namespace std;

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res += catalan(i) * catalan(n-1-i);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter the limit n:\n";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<catalan(i)<<" ";
    }
    cout<<endl;
    return 0;
}