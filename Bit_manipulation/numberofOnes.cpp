#include<iostream>
using namespace std;

int numberofones(int n){
    int count =0;
    while(n){
        n = n & n-1;
        count++;
    }
    return count;
}


int main(){
    int x;
    cout<<"Enter a number:\n";
    cin>>x;
    cout<<"Number of ones in "<<x<<" is = "<<numberofones(x);
    return 0;
}