//Program to solve the sliding window maximum problem using deque(Doubly ended queue). Time complexity O(n)
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the window size:\n";
    cin>>k;
    
    vector<int> a(n);
    cout<<"Enter the "<<n<<" elements:\n";
    for(auto &i: a){
        cin>>i;
    }

    vector<int> ans;
    deque<int> q;
    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=k; i<n; i++){
        if(q.front() == i-k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    cout<<"Maximum among each window of "<<k<<" size: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}