//Program to implement queue using array method
#include<iostream>

using namespace std;

class queue{
    int* arr;
    int front;
    int back;

    public:
    queue(int n){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int n, int val){
        if(back == n-1){
            cout<<"Queue is full. Cannot insert element\n";
            return;
        }
        back++;
        arr[back] = val;
        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front == -1 || front>back){
            cout<<"Queue is empty. Cannot remove element.\n";
            return;
        }

        front++;
    }

    int peek(){
        if(front == -1 || front>back){
            cout<<"Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front>back){
           // cout<<"Queue is empty.\n";
            return true;
        }
        return false;
    }

};

int main(){
    int n;
    cout<<"Enter the queue size:\n";
    cin>>n;

    //calling the parameterized constructor to initialize the elements with default value
    queue d(n);

    int x;
    int choice;
     //Implementing a menu driven program
    do
    {
        cout<<"---MENU---\n1. Insert an element.\n2. Delete an element.\n3. Display the first element.\n4. Check if queue is empty.\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the element:\n";
                    cin>>x;
                    d.enqueue(n,x);
                    break;
            case 2: cout<<"Dequeue operation performed.\n";
                    d.dequeue();
                    break;
            case 3: cout<<"Top most element is: "<<d.peek()<<endl;
                    break;
            case 4: cout<<d.empty()<<endl;
                    break;
            case 5: cout<<"Exiting program...\n";
                    break;
            default: cout<<"Enter a valid choice.\n";
        }

    } while (choice!=5);
    return 0;
    
}