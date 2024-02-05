//outputting the index of the first repeating element
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;

    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int minIdx = INT16_MAX;
    const int N = 1e6 + 2;

    int idx[N];
    for(int i=0;i<N;i++){
        idx[i] = -1;
    }

    for(int i=0;i<n;i++){
        if(idx[a[i]] != -1){
            minIdx = min(minIdx, idx[a[i]]);
        }
        else{
            idx[a[i]] = i;
        }
    }

    if(minIdx == INT16_MAX){
        cout<<"-1"<<endl;
    }
    else cout<<minIdx+1<<endl;

    return 0;
}