//Program to implement Floyd's algorithm to detect and remove the cycles in an linked list
//m=l*(j-(2*i))-n; 
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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void makeCycle(node* head, int pos){
    node* temp = head;
    node* startNode;

    int count=0;

    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next=startNode;

}

void removeCycle(node* &head){
    node* slow=head;
    node* fast = head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main(){
    node* head = NULL;
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertAtTail(head,x);
    }
    // display(head);
    // bool y = detectCycle(head);
    // if(y){
    //     cout<<"Cycle is present\n";
    // }
    // int pos;
    // cout<<"Enter the position you want to make cycle:\n";
    // cin>>pos;
    // makeCycle(head,pos);
    // y = detectCycle(head);
    // if(y){
    //     cout<<"Cycle is present:\n";
    // }
    // cout<<"Removing Cycle:\n";
    // removeCycle(head);
    // y = detectCycle(head);
    // if(y){
    //     cout<<"Cycle is present:\n";
    // }
    // display(head);

    // return 0;
}