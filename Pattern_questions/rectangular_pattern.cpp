#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter number of rows and columns\n";
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
         if(j==0 || j==b-1 || i==0 || i== a-1)
                    cout<<" * ";
                else cout<<"   ";
        }
        cout<<endl;
    }
}