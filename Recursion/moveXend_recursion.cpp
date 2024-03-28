//Program to move x to the end in a string 
#include<iostream>
using namespace std;

string moveX(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = moveX(s.substr(1));
    if(ch=='x'){
        return (ans+ch);
    }
    return (ch+ans);
}

int main(){
    char s[25];
    cout<<"Enter a string:\n";
    fgets(s,25,stdin);
    cout<<"Final string = \n"<<moveX(s);
    return 0;
}