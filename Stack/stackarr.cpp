//Program to implement stack using classes and array implementation technique
#include<iostream>
using namespace std;

#define n 100

class stack{
    int * arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }
    //adds an element to the top of the stack
    void push(int x){
        if(top == n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    //removes the top most element from the stack
    void pop(){
        if(top == -1){
            cout<<"No element to pop"<<endl;
            return;
        }
        top--;
    }
    //Displays the top  most element in the stack
    int Top(){
        if(top == -1){
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    //Displays 1 if the stack is empty or else 0
    bool empty(){
        return top==-1;
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
        cout<<"---MENU---\n1. Push an element.\n2. Pop an element.\n3. Display the top element.\n4. Check if stack is empty.\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the element:\n";
                    cin>>x;
                    st.push(x);
                    break;
            case 2: cout<<"Pop operation performed.\n";
                    st.pop();
                    break;
            case 3: cout<<"Top most element is: "<<st.Top()<<endl;
                    break;
            case 4: cout<<st.empty()<<endl;
                    break;
            case 5: cout<<"Exiting program...\n";
                    break;
            default: cout<<"Enter a valid choice.\n";
        }

    } while (choice!=5);
    return 0;
    
}
