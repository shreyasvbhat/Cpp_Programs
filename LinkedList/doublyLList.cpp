//Program to implement doubly linked list
#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* prev;
     node* next;

    node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    n->prev = temp;
    temp->next = n;
}

void deleteAtHead(node* &head){
    
    node* toDelete = head;
    head = head->next;
    head->prev = NULL;

    delete toDelete;
}

void deleteAtPos(node* &head, int pos){
    node* temp = head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    int count=1;
    while(temp!=NULL && count!=pos){
        temp= temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp!=NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void display(node* head){
    node* temp = head;
    cout<<"NULL<=>";
    while(temp!=NULL){
        cout<<temp->data<<"<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head =NULL;
    insertAtTail(head,2);
    insertAtTail(head,4);

    insertAtTail(head,6);

    insertAtTail(head,8);
    display(head);
    insertAtHead(head,10);
    display(head);


    return 0;
}