#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxNo = arr[0];
    int minNo = arr[0];

    for(int i=0;i<n;i++){
        if(maxNo < arr[i])
          maxNo = arr[i];
        if(minNo > arr[i])
         minNo = arr[i];
    }
    cout<<maxNo<<"  "<<minNo<<endl;

    return 0;
}