//Program to append last k nodes to the starting of the list
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

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int lengthNode(node* head){
    node* temp = head;
    int l=0;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* appendNode(node* &head, int k){
    int len = lengthNode(head);
    if(k>len){
        cout<<"Invalid value of k";
        return NULL;
    }
    node* newHead;
    node* newTail;
    node* tail=head;
    int count=1;
    while(tail->next!=NULL){
        if(count==len-k+1){
            newTail = tail; 
        }
        if(count==len-k+2){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
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
    display(head);
    int k;
    cout<<"Enter the value of k:\n";
    cin>>k;
    node* newHead = appendNode(head, k);
    display(newHead);
}