//Program to find thr three elements whose sum is equal to target
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    int target;
    cout<<"Enter the target:\n";
    cin>>target;
    vector<int> a(n);
    vector<vector<int>> ans;
    cout<<"Enter the elements:\n";
    for(auto &i: a){
        cin>>i;
    }
    sort(a.begin(), a.end());
    bool flag = false;
    for(int i=0;i<n;i++){
        int low = i+1;
        int high = n-1;
        while(low<high){
            int sum = a[i]+a[low]+a[high];
            if(sum == target){
                flag = true;
                ans.push_back({a[i],a[low],a[high]});
                break;
            }else if(sum > target){
                high--;
            }else low++;
        }
    }
    if(flag){
        cout<<"True\n";
        for(auto i: ans){
            cout<<"[";
            for(auto j: i){
                cout<<j<<"  ";
            }
            cout<<"]";
        }
    }else cout<<"False";
    return 0;
}