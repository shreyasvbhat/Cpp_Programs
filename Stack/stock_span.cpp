//Program to calculate the stock span i.e. the number of days the stock was at a low price(considering the present day
// and the previous day) return the span array
#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> prices){
    stack<pair<int,int>> st;
    vector<int> ans;
    for(auto price: prices){
        int days = 1;
        while(!st.empty() &&  st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push({price,days});
        ans.push_back(days);
    }
    return  ans;
}

int main(){
    vector<int> a;
    int n;
    int i;
    cout<<"Enter the number of days:\n";
    cin>>n;
    cout<<"Enter the prices for each day:\n";
    for(int x =0; x<n;x++){
        cin>>i;
        a.push_back(i);
    }
    vector<int> sol = stockSpan(a);
    cout<<"Span is: ";
    for(auto p: sol){
        cout<<p<<" ";
    }
    cout<<endl;
    return 0;
}