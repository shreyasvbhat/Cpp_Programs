//Program to print all permutation using inbuilt function
#include<iostream>
#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> ans;

int main(){
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements:\n";
    for(auto &i : a){
        cin>>i;
    }
   do{
    ans.push_back(a);
   }while(next_permutation(a.begin(),a.end()));
    cout<<"Permutation is:\n";
    for(auto v: ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;

}