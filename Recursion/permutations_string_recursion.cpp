//Program to print the permutaion of a string using recursion
#include<iostream>
using namespace std;

void permu(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permu(ros, ans+ch);
    }
}

int main(){
    char str[25];
    cout<<"Enter a string:\n";
    cin>>str;
    permu(str,"");
    return 0;
}