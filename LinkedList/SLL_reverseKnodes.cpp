//Program to reverse a Singly linked list
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

node* revesre(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextE;
    while(curr!=NULL){
        nextE = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr=nextE;
    }

    return prev;
}

node* reverseRecursion(node* &head){
    node* newHead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseKnode(node* head, int k){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextprt;
    int count=0;
    while(currptr!=NULL && count<k){
        nextprt = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextprt;
        count++;
    }
    if(nextprt!=NULL){
        head->next = reverseKnode(nextprt, k);
    }

    return prevptr;
}

int main(){

    node* head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtHead(head,10);
    insertAtTail(head,43);
    insertAtTail(head,20);
    insertAtHead(head,16);
    display(head);
    node* newHead = revesre(head);
    display(newHead);
    // node* newHead2 = reverseRecursion(head);
    // display(newHead2);
    int k=2;
    node* newHead3 = reverseKnode(head, k);
    display(newHead3);

    return 0;
}