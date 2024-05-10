//Program to find the largest rectangle in a histogram and return its area
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> a){
    int ans = 0, i=0, n= a.size();
    a.push_back(0);
    stack<int> st;
    while(i<n){
        while(!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty()){
                ans = max(ans, h*i);
            }else{
                int len = i - st.top() - 1;
                ans = max(ans, h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> arr;
    int x;
    int n;
    cout<<"Enter the number of bars in a histogram:\n";
    cin>>n;
    cout<<"Enter the the length of each bar in a histogram:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    cout<<maxArea(arr);
}