//Program to reverse a stack without using a dummy stack
#include<iostream>
#include<stack>
using namespace std;

//recursive function which is used to insert the "ele" element at the bottom of the stack
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();

    insertAtBottom(st, ele);
    st.push(topele);
}

//recursive stack operation to reverse a stack
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}

int main(){
    stack<int> st;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    int x[n];
    cout<<"Enter the elements:\n";
    for(int i=0; i<n;i++){
        cin>>x[i];
        st.push(x[i]);
    }
    cout<<"Before reversing a stack elements are:\n";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    for(int i=0; i<n;i++){
        st.push(x[i]);
    }
    reverseStack(st);
    cout<<"After reversing a stack elements are:\n";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}