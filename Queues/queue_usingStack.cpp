//Program to implement queue using stack
#include<iostream>
#include<stack>
using namespace std;

//using two stacks which intern results in time complexity of dequeue operation becoming O(n) in worst case senario
class queue{
    stack<int> st1;
    stack<int> st2;

    public:
    void enqueue(int x){
        st1.push(x);
    }
    int dequeue(){
        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty.\n";
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topVal = st2.top();
        st2.pop();
        return topVal;
    }

    bool empty(){
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }

};

//Using only one stack and using recursive call to perfrom the dequeue operation.
class queue2{
    stack<int> st;
    public:
    void enqueue(int x){
        st.push(x);
    }
    int dequeue(){
        if(st.empty()){
            cout<<"Queue is empty.\n";
            return -1;
        }
        int x = st.top();
        st.pop();
        if(st.empty()){
            return x;
        }
        int item = dequeue();
        st.push(x);    
        return item;    
    }

    bool empty(){
        if(st.empty()){
            return true;
        }
        return false;
    }

};

int main(){
    queue d;
    queue2 d2;

    int x,m,n;
    int choice;

     //Implementing a menu driven program
    do
    {
        cout<<"---MENU---\n1. Insert an element.\n2. Delete an element.\n3. Display the recently deleted element.\n4. Check if queue is empty.\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the element:\n";
                    cin>>x;
                    d.enqueue(x);
                    d2.enqueue(x);
                    break;
            case 2: cout<<"Dequeue operation performed.\n";
                    m = d.dequeue();
                    n = d2.dequeue();
                    break;
            case 3: cout<<"Recently deleted element is: "<<m<<endl;
                    cout<<"Recently deleted element is: "<<n<<endl;
                    break;
            case 4: cout<<d.empty()<<endl;
                    cout<<d2.empty()<<endl;
                    break;
            case 5: cout<<"Exiting program...\n";
                    break;
            default: cout<<"Enter a valid choice.\n";
        }

    } while (choice!=5);
    return 0;
}