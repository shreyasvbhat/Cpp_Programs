//Program to check if a string is palindrome or not
#include<iostream>
using namespace std;

int main(){
    int n,i=0;
    cout<<"Enter the limit:\n";
    cin>>n;
    bool flag=1;
    char arr[n+1];
    cout<<"Enter the string:\n";
    cin>>arr;

    for(int i=0;i<n;i++){
        if(arr[i] != arr[n-1-i]){
            flag = 0;
            break;
        }
    }

    if(flag){
        cout<<"Its a palindrome\n";
    }
    else cout<<"Not a palindrome\n";

    return 0;
}