//Program to check if the entered string has balanced parenthesis or not using stack
#include<iostream>
#include<stack>

using namespace std;


//function to check if the string contains balanced parenthesis. It returns true if it is balanced or else false
bool valid(string s){
    stack<char> st;
    bool ans = true;
    int n = s.size();
    for(int i=0;i<n;i++){

        if(s[i] == '(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }
    }
    if(!st.empty()){
        return false;
    }else return ans;
}

int main(){
    string s;
    cout<<"Enter the parenthesis string:\n";
    getline(cin, s);
    if(valid(s)){
        cout<<"It has balanced parenthesis\n";
    }else{
        cout<<"It has unbalanced parenthesis\n";
    }
    return 0;
}