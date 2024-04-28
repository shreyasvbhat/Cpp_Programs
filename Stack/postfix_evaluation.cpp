//Program to evalute a postfix expression using stack
//Time complexity O(n), where n is the length of the postfix expression string
#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

//Function to evaluate postfix expression
int postfixExpression(string s){

    stack<int> st;

    for(int i=0;i<s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '%':
                st.push(op1%op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();

}


int main(){
    string s;
    cout<<"Enter a valid postfix expression:\n";
    getline(cin,s);
    cout<<"Final Answer: "<<postfixExpression(s)<<endl;

    return 0;
}