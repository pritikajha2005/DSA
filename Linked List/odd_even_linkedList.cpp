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

Node* oddEvenList(Node* head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;

    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        odd=odd->next;

        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evenHead;

    return head;
}

int main(){
    Node* head=nullptr;
    insert(head, 1);
    insert(head, 4);
    insert(head, 2);
    insert(head, 5);
    insert(head, 3);

    cout<<"Original list: ";
    printList(head);

    head=oddEvenList(head);

    cout<<"After Odd Even Rearrangement: ";
    printList(head);

    return 0;
}