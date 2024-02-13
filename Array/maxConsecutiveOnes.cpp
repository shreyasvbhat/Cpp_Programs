//Program to  calculate the maximum length of the subarray which contains only 1's and we can change only k elments
//to attain the max length
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the number of changes that can be done to make the subarray longest:\n";
    cin>>k;
    vector<int> a(n);
    cout<<"Enter the elements:\n";
    for(auto &i: a){
        cin>>i;
    }
    int zeroct =0, ans=0, i=0;
    for(int j=0;j<n;j++){
        if(a[j]==0){
            zeroct++;
        }
        while(zeroct>k){
            if(a[i]==0){
                zeroct--;
            }
            i++;
        }
        //zeroct <= k
        ans = max(ans, j-i+1);
    }
    cout<<"Max length = "<<ans;
    return 0;
}