//Program to implement queue using linkedlist method
#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

class queue{
    node* front;
    node* back;

    public:

    queue(){
        front = NULL;
        back = NULL;
    }

    void enqueue(int val){
        node* n = new node(val);
        if(front == NULL){
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back=n;
    }

    void dequeue(){
        if(front  == NULL){
            cout<<"Queue underflow.\n";
            return;
        }
        node* toDelete = front;
        front = front->next;

        delete toDelete;
    }

    int peek(){
        if(front == NULL){
            cout<<"Queue is empty.\n";
            return -1;
        }

        return front->data;
    }

    bool empty(){
        if(front == NULL ){
            return true;
        }
        return false;
    }

};

int main(){

    //creating a object for the class queue which will automatically call the  default constructor
    queue d;

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
                    d.enqueue(x);
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