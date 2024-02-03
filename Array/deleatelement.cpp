//At most 2 duplicates
#include<iostream>
using namespace std;
int main(){
    int arr[]= {1,1,1,2,2,3};
    int count=1;
    int j=1;
    for(int i=1;i<6;i++){
        if(arr[i-1]==arr[i] && count<2){
            arr[j]=arr[i];
            j++;
            count++;
        }else{ if(arr[i-1]!=arr[i]){
            arr[j] = arr[i];
            j++;
            count=1;
        }
            count = 0;
        }
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<j<<" "<<count;
    return 0;
}