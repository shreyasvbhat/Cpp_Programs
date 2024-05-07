//Program to find the maximum units of rainwater which can be trapped between all the bars in a place
#include<bits/stdc++.h>
using namespace std;

int trapRainWater(vector<int> a){
    stack<int> st;
    int n= a.size();
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] < a[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> a;
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    cout<<"Maximum amount of water that can be stored is = "<<trapRainWater(a)<<" cubic units"<<endl;
    return 0;
}