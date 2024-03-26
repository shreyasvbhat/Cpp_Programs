//Program to find the possible combination of a of letters in a keypad phone based on two numbers
#include<iostream>
using namespace std;
string keypadArry[] = {"", "./", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string code = keypadArry[ch-'0'];
    string ros = s.substr(1);

    for(int i=0;i<code.length();i++){
        keypad(ros, ans+code[i]);
    }
    
}

int main(){
    char str[10];
    cout<<"Enter the digits:\n";
    cin>>str;
    keypad(str,"");
    return 0;
}