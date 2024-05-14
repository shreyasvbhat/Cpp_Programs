//Solving the sliding window maximum problem using vector and multiset. Time complexity is O(nlogn)
// #include<iostream>
// #include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter the number of elements and the window size:\n";
    cin>>n>>k;
    vector<int> a(n);
    cout<<"Enter the "<<n<<" elements:\n";
    for(auto &i: a){
        cin>>i;
    }

    vector<int> ans;
    multiset<int, greater<int>> s;
    for(int i=0; i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());

    for(int i=k; i<n; i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    
    cout<<"Maximum among each window of "<<k<<" size: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}