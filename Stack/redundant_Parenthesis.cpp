//Program to check if the expression contains unnecessary brackets. If it does contain then return true or else return false
#include<bits/stdc++.h>
using namespace std;

bool redundant(string s){
    stack<char> st;
    bool ans = false;
    for(int i=0;i<s.length(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            if(st.top() == '('){
                ans = true;
            }
            while(st.top() == '+' || st.top()  == '-' || st.top()  == '*' || st.top()  == '/'){
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter a valid expression:\n";
    getline(cin, s);
    if(redundant(s)){
        cout<<"Expression contains redundant parenthesis\n";
    }else{
        cout<<"Expression does not contain redundant parenthesis\n";
    }
    return 0;
}