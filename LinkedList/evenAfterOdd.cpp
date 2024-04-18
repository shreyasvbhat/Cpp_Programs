//Program to rearrange the linkedlist such that even elements come after odd elements
//Time complexity = O(n), where n = length of the linked list
//if the first element is even then the operation brings all the even elements to the begining otherwise
//the odd elements come at the begining
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
    node* n= new node(val);
    n->next = head;
    head=n;
    return;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head== NULL){
        head =n;
        return;
    }

    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void evenAfterOdd(node* &head){
    node* odd =head;
    node* even = head->next;
    node* start = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = start;
    // if(odd->next!=NULL){
    //     even->next = NULL;
    // }
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
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
    display(head1);
    evenAfterOdd(head1);
    display(head1);

    return 0;
}