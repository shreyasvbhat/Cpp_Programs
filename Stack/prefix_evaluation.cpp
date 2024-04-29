//Program to evalute a prefix expression using stack
//Time complexity O(n), where n is the length of the prefix expression string
#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

//Function to evaluate prefix expression
int prefixExpression(string s){

    stack<int> st;

    for(int i=s.length()-1;i>=0;i--){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
    cout<<"Enter a valid prefix expression:\n";
    getline(cin,s);
    cout<<"Final Answer: "<<prefixExpression(s)<<endl;

    return 0;
}