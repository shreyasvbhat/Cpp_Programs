//Program to implement stack using queue method 2
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

    void push(int val){
        q1.push(val);
        N++;
       
    }
    //pop operation is perfromed in O(n) in worst case senario in this method
    void pop(){
        if(q1.empty()){
            cout<<"Stack is empty. Cannot pop the element.\n";
            return;
        }
        while (q1.size() != 1){
            q2.push(q1.front());
            q1.pop();   
        }
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int size(){
        return N;
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is empty.\n";
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
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
                    break;
            case 6: cout<<"Exiting program...\n";
                    break;
            default: cout<<"Enter a valid choice.\n";
        }

    } while (choice!=6);

    return 0;
}