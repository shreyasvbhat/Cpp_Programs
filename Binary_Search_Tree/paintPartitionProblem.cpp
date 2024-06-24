//Program to find the minimum number of time needed to paint all the board by m painters
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findFeasible(int boards[], int n, int limit){
    int sum = 0, painters = 1;
    for(int i=0; i<n; i++){
        sum += boards[i];
        if(sum > limit){
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[], int n, int m){
    int totalLength = 0, k = 0;
    for(int i=0; i<n; i++){
        k = max(k, boards[i]);
        totalLength += boards[i];
    }
    int start = k;
    int end = totalLength;
    while(start < end){
        int mid = (start + end)/2;
        int painters = findFeasible(boards, n, mid);
        if(painters <= m){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
}

int main(){
    int n,m;
    cout<<"Enter the number boards:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the lengths of "<<n<<" boards:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of painters available:\n";
    cin>>m;
    cout<<"Minimum number of time needed to paint all the boards = "<<paintersPartition(arr, n, m)<<endl;

    return 0;
}