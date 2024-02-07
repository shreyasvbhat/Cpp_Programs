//Program to find the length of the longest substring without repeating character
#include<bits/stdc++.h>
using namespace std;

int main(){

    // int n;
    // cout<<"Enter the string length:\n";
    // cin>>n;
    string s;
    cout<<"Enter the string:\n";
    getline(cin,s);
    vector<int> dict(256,0);
    int start = -1;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(dict[s[i]] > start){
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        ans = max(ans, i-start);
    }
    cout<<"Max length = "<<ans;
    return 0;
}