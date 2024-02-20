//Program to find the smallest missing +ve number in an array
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the  elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    const int N =1e6 + 2;
    bool ch[N];
    for(int i=0;i<N;i++){
        ch[i] = 0;
    }

    for(int i=0;i<n;i++){
        if(a[i]>=0){
            ch[a[i]] = 1;
        }
    }
    int ans =-1;
    for(int i=0;i<N;i++){
        if(ch[i] == 0){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;

}