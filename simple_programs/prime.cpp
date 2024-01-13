#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flag =1;
            break;
        }
    }
    if(flag)
     cout<<"Non-Prime";
    else cout<<"Prime";

    return 0;
}