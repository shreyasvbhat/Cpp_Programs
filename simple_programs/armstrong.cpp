#include<iostream>
using namespace std;

int main(){
    int n,rem, sum=0,x;
    cin>>n;
    x=n;
    while(n>0){
        rem = n%10;
        sum = sum + (rem*rem*rem);
        n = n/10;
    }
    if(sum == x)
     cout<<"Its a armstrong number";
    else 
     cout<<"Its not a armstrong number";

return 0;
}