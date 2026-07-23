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

Node* removeDuplicate(Node* head){
    Node* current=head;

    while(current!=nullptr && current->next!=nullptr){
        if(current->data==current->next->data){
            Node* duplicate=current->next;
            current->next=current->next->next;
            delete duplicate;
        }
        current=current->next;
    }
    return head;
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
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 4);

    cout<<"Original List: ";
    printList(head);

    head=removeDuplicate(head);

    cout<<"After Removing Duplicates: ";
    printList(head);

    return 0;
}