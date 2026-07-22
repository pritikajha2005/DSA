#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

void insert(Node*& head, int val){
    Node* newNode= new Node(val);

    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeNthFromEnd(Node* head, int n){
    Node* fast=head;
    Node* slow=head;
    
    //Moving fast n steps ahead
    for(int i=0; i<n; i++){
        if(fast==NULL){
            return head;
        }
        fast=fast->next;
    }
    
    //head has to be removed
    if(fast==NULL){
        Node* newHead=head->next;
        delete head;
        return newHead;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main(){

    Node* head=nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout<<"Original list: ";
    printList(head);

    int n;
    cout<<"Enter n: ";
    cin>>n;

    head=removeNthFromEnd(head, n);

    cout<<"After deletion: ";
    printList(head);

    return 0;
}