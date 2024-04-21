//Program to implement basic Linked List operations
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
    temp->next=n;

}

void insertAtHead(node* &head, int val){
    node* n= new node(val);
    n->next = head;
    head=n;
    return;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }

    node* temp =head;
    while(temp->next->data != val){
        temp=temp->next;
    }
    node *deletingele = temp->next;
    temp->next = temp->next->next;
    delete deletingele;
}

void search(node* head, int key){
    node* temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->data==key){
            cout<<"Element "<<key<<" found in "<<count<<" Location"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Element not found\n";
    return;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtHead(head,10);
    search(head,9);
    search(head,5);
    display(head);
    deletion(head,3);
    display(head);
    deleteAtHead(head);
    display(head);

    return 0;
}