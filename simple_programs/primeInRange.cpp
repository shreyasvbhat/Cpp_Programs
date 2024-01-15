#include<iostream>
using namespace std;

int main(){
    int a,b,count=1;
    cin>>a>>b;

    for(int num=a;num<=b;num++){
        int i;
        for(i=2;i<num;i++){
            if(num%i==0){
                break;
            }
        }
        if(i==num){
            count++;
            cout<<num<<endl;
        }
    }
    if(count==1){
        cout<<"No Prime number found between "<<a<<" and "<<b<<endl;
    }

    return 0;
}