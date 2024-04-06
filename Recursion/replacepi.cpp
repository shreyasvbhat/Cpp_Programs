//Program to replace pi 3.14 using recursion
#include<iostream>
using namespace std;

void replacepi(string s){

    if(s.length()==0){
        return;
    }

    if( (s[0]=='p') && (s[1]=='i')){
        cout<<"3.14";
        replacepi(s.substr(2));
    }else{
        cout<<s[0];
        replacepi(s.substr(1));
    }
}

int main(){
    char c[25];
    cout<<"Enter a string:\n";
    cin.getline(c,25);
    replacepi(c);
    return 0;
}