//Program to find the maximum value out of robbery (0-1 knapsack problem)
#include<iostream>
using namespace std;

int knapsack(int value[], int w[], int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(w[n-1]>W){
        return knapsack(value, w, W, n-1);
    }

    return (max(knapsack(value, w, W-w[n-1], n-1)+value[n-1], knapsack(value, w, W, n-1)));
}


int main(){
    int val[10], wg[10], W,n;
    cout<<"Enter the number of items:\n";
    cin>>n;
    cout<<"Enter the weight of each item:\n";
    for(int i=0;i<n;i++){
        cin>>wg[i];
    }
    cout<<"Enter the value for respective item:\n";
    for(int i=0; i<n;i++){
        cin>>val[i];
    }
    cout<<"Enter the maximum weight the knapsack can hold:\n";
    cin>>W;
    cout<<"Maximum value: "<<knapsack(val,wg,W,n)<<endl;
    return 0;
}