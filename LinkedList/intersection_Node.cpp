//Program to find the intersectoin of two LinkedList
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
    node* current = head;
    if(head==NULL){
        head = n;
        return;
    }
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = n;
}

void display(node* head){
    node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int len(node* &head){
    node* temp = head;
    int le = 0;
    while(temp->next!=NULL){
        le++;
        temp = temp->next;
    }
    return le;
}

int intersectionCheck(node* head1, node* &head2){
    node* ptr1;
    node* ptr2;
    int d=0;
    int l1 = len(head1);
    int l2 = len(head2);
    if(l1>l2){
        d= l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){

        if(ptr1==ptr2){
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;

}

void intersect(node* &head1, node* &head2, int pos){
    node* ptr1 = head1;
    node* ptr2 = head2;
    while(ptr2->next!=NULL){
        ptr2 = ptr2->next;
    }
    int count = 1;
    while(ptr1!=NULL && count<pos){
        ptr1 = ptr1->next;
        count++;
    }
    if(ptr1==NULL){
        cout<<"Invalid position\n";
        return;
    }
    ptr2->next = ptr1;
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
    int pos;
    cout<<"Enter the position to intersect:\n";
    cin>>pos;
    intersect(head1, head2, pos);
    display(head1);
    display(head2);

    cout<<"Intersection result is: "<<intersectionCheck(head1, head2)<<endl;
}