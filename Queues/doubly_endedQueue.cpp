//Program to illustrate the use of dobly ended queue(dequeue)
#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> q;
    int x;
    int choice;
    do{
        cout<<"---MENU---\n1. Insert at front.\n2. Insert at back.\n3. Delete at front.\n4. Delete at back.\n5. Display the Dequeue.\n6. Exit.\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element:\n";
            cin>>x;
            q.push_front(x);
            break;
        case 2: 
            cout<<"Enter the element:\n";
            cin>>x;
            q.push_back(x);
            break;
        case 3: 
            q.pop_front();
            cout<<"Pop operation performed\n";
            break;
        case 4: 
            q.pop_back();
            cout<<"Pop opreation performed\n";
            break;
        case 5:
            for(int i = 0; i< q.size(); i++){
                cout<<q.front()<<" ";
                q.push_back(q.front());
                q.pop_front();                
            }
            cout<<endl;
            break;
        case 6:
            cout<<"Exiting...\n";
            break;
        default: cout<<"Enter a valid choice\n";
        }
    }while(choice!=6);

    return 0;
}