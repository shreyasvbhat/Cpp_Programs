//Program to implement stack using queue method 1
#include<iostream>
#include<queue>
using namespace std;

class stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stack(){
        N = 0;
    }

    //push operation is performed in O(n) in worst case senario in this method
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        if(q1.empty()){
            cout<<"Stack is empty. Cannot pop the element.\n";
            return;
        }
        q1.pop();
        N--;
    }

    int size(){
        return N;
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is empty.\n";
            return -1;
        }
        return q1.front();
    }
    
    bool empty(){
        if(q1.empty()){
            return true;
        }
        return false;
    }

};

int main(){

    int x;
    //creating a object "st" for the stack class
    stack st;
    int choice;
    //Implementing a menu driven program
    do
    {
        cout<<"---MENU---\n1. Push an element.\n2. Pop an element.\n3. Display the top element.\n4. Check if stack is empty.\n5. Display the size of the Stack.\n6. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the element:\n";
                    cin>>x;
                    st.push(x);
                    break;
            case 2: cout<<"Pop operation performed.\n";
                    st.pop();
                    break;
            case 3: cout<<"Top most element is: "<<st.top()<<endl;
                    break;
            case 4: cout<<st.empty()<<endl;
                    break;
            case 5: cout<<st.size()<<endl;
            case 6: cout<<"Exiting program...\n";
                    break;
            default: cout<<"Enter a valid choice.\n";
        }

    } while (choice!=6);

    return 0;
}