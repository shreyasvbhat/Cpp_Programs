//Program to remove duplicates in a string of continous order like aaabbbcceeeffsss
#include<iostream>
using namespace std;

string remDup(string s){

    if(s.length()==0){
        return "";
    }
    char ch= s[0];
    string ans = remDup(s.substr(1));
    if(ch == ans[0]){
        return ans;
    }
    return (ch+ans);

}

int main(){
    char s[25];
    cout<<"Enter a sting:\n";
    fgets(s,25,stdin);
    cout<<"After removing duplicates\n";
    cout<<remDup(s);
    return 0;
}