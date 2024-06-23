//Program to allocate all the books such that it has to be divided among m students consecutively.
//Allocate the pages in such a way that maximum pages allocated to a student is minimum
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int min){
    int studentsRequired = 1, sum = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > min){
            return false;
        }
        if(sum+arr[i] > min){
            studentsRequired++;
            sum = arr[i];
            if(studentsRequired > m){
                return false;
            }
        }else{
            sum += arr[i];
        }
    }
    return true;
}

int allocateMinimumPages(int arr[], int n, int m){
    if(m > n){
        //there is more students than books, so allocation not possible.
        return -1;
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int ans = INT_MAX;
    int start=0, end = sum;
    while(start < end){
        int mid = (start + end)/2;
        if(isPossible(arr, n, m, mid)){
            ans = min(ans, mid);
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter the number of books:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the number of pages in "<<n<<" books:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of students:\n";
    cin>>m;

    cout<<"Minimum number of pages alloted to each student = "<<allocateMinimumPages(arr, n, m)<<endl;

    return 0;
}