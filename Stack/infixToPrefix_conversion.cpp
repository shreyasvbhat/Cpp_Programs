//Program to convert a infix ecpression to prefix expression using stack

#include<iostream>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

//function to check the precidence of an operator
int prec(char c){
    if(c=='^'){
        return 3; 
    }else if(c=='-' || c=='+'){
        return 1;
    }else if(c=='*' || c=='/'){
        return 2;
    }else{
        return -1;
    }
}

//function to convet infix expression to prefix expression.
string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' && s[i]<='z')  ||  (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }else if(s[i] == ')'){
            st.push(s[i]);
        }else if(s[i] == '('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    string s;
    cout<<"Enter a valid infix expression:\n";
    getline(cin,s);
    cout<<"Final Answer: "<<infixToPrefix(s)<<endl;

    return 0;
}