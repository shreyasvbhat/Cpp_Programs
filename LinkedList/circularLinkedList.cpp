//Program to do operations on circular linked list
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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        n->next =n;
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head =n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    
}

void deleteAtHead(node* &head){

    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
     node* toDelete=head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;

}

void deletion(node* &head, int pos){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    int count = 1;
    node* temp = head;
    
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }
    
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"(head)"<<endl;
}

int main(){
    node* head1 = NULL;
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertAtTail(head1,x);
    }
    insertAtHead(head1,9);
    display(head1);
    deletion(head1, 3);
    display(head1);
    deleteAtHead(head1);
    display(head1);

    return 0;
}