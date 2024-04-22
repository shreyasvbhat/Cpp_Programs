//Program to merge two sorted linked list TimeComplexity= O(n+m)
#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* next;
    
    node(int val){
        data= val;
        next = NULL;
    }

};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head= n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

node* merge(node* &head1, node* &head2){
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummyNode = new node(-1);
    node* ptr3 = dummyNode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
}

node* mergeRecurssion(node* &head1, node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecurssion(head1->next, head2);
    }else{
        result = head2;
        result->next = mergeRecurssion(head1, head2->next);
    }

    return result;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int n,m;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertAtTail(head1,x);
    }
    display(head1);
    cout<<"Enter the number of elements:\n";
    cin>>m;
    cout<<"Enter the elements:\n";
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        insertAtTail(head2,x);
    }
    display(head2);

    //node* newHead = merge(head1, head2);
    node* newHead2 = mergeRecurssion(head1, head2);
    display(newHead2);

    return 0;
}