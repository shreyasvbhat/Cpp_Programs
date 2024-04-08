//Program to print all substring using recursion
#include<iostream>
using namespace std;

void subst(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    subst(ros, ans);
    subst(ros, ans+ch);
}

int main(){
    char st[25];
    cout<<"Enter a string:\n";
    cin>>st;
    subst(st,"");
    return 0;
}