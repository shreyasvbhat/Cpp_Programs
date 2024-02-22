//finding the subarray whos sum of elements is equal to the enetered sum
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int s;
    cout<<"Enter the sum:\n";
    cin>>s;
    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0,j=0,sum=0,st=0,en=0;
    while(j<n && sum+a[j] <= s){
        sum += a[j];
        j++;        
    }
    if(sum == s){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }

    while(j<n){
        sum += a[j];
        while(sum>s){
            sum -= a[i];
            i++;
        }

        if(sum == s){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

    cout<<st<<" "<<en<<endl;
    return 0;
}