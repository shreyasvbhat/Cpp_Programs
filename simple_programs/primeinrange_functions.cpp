#include<iostream>
#include<math.h>
using namespace std;

bool prime(int x){
    for(int j=2;j<=sqrt(x);j++){
        if(x%j==0){
            return false;
        }
    }
    return true;
}


int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(prime(i))
         cout<<i<<" ";
    }

    return 0;
}

