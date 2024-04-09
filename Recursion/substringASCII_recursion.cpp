//Program to find print substring with ascii format
#include<iostream>
#include<string>
using namespace std;

void subseq(string str, string ans){
    if (str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=str[0];
    int code=ch;
    string ros = str.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros, ans+to_string(code));
}

int main(){

    char str[25];
    cout<<"Enter a string:\n";
    cin>>str;
    subseq(str,"");
    return 0;
}