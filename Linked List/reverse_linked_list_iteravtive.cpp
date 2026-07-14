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

Node* reverseList(Node* head){
    Node* current=head;
    Node* previous=nullptr;

    while(current!=nullptr){
        //Store the next node
        Node* nextNode=current->next;
        //Reverse current link
        current->next=previous;
        //Move pointers forward
        previous=current;
        current=nextNode;
    }
    return previous;
}

void insert(Node*& head, int val){
    Node* newNode= new Node(val);

    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    Node* head=nullptr;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);   

    cout<<"Original list: ";
    printList(head);

    head=reverseList(head);

    cout<<"Reversed list: ";
    printList(head);
    
    return 0;
}