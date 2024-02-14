//Program to find the maximum sum of a circular subarray
#include<iostream>
#include<climits>

using namespace std;

int kadane(int arr[], int n){
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i=0;i<n;i++){
        currentSum += arr[i];
        if(currentSum<=0){
            currentSum =0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int wrapSum, nonWrapSum;
    nonWrapSum = kadane(a,n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum += a[i];
        a[i] = -a[i];
    }
    wrapSum = sum + kadane(a,n);

    cout<<max(wrapSum, nonWrapSum)<<endl;
    return 0;
}