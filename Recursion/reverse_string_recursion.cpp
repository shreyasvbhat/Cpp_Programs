//Program to reverse a string using recursion
#include<iostream>
//#include  <bits/stdc++.h>

using namespace std;

void reverse(string s){

    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

int main(){
    char s[25];
    cout<<"Enter a String:\n";
    cin.getline(s,25);
    reverse(s);

    return 0;
}