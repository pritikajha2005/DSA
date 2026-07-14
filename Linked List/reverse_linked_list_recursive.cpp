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
    if(head==nullptr || head->next==nullptr){
       return head;
    }

    Node* newHead=reverseList(head->next);

    head->next->next=head;
    head->next=nullptr;

    return newHead;
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
    while(temp!=nullptr){
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
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    
    cout<<"Original list: ";
    printList(head);

    head=reverseList(head);

    cout<<"Reversed list: ";
    printList(head);
    
    return 0;

}