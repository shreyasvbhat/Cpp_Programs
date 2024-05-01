//Program to reverse a sentence using stack
#include<iostream>
#include<stack>

using namespace std;

void reverseSentence(string s){
    stack<string> st;

    //storing each word seperatly and pusing it into the stack
    for(int i=0;i<s.length();i++){

        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    //printing the stack elements
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s;
    cout<<"Enter a sentence:\n";
    getline(cin, s);

    reverseSentence(s);

    return 0;
}