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

Node* rotateList(Node* head, int k){

    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* tail=head;
    int length=1;

    while(tail->next!=nullptr){
        tail=tail->next;
        length++;
    }

    k=k%length;

    // K is multiple of the lenght of list.
    if(k==0){
        return head;
    }
      
    //Rotated circular
    tail->next=head;
    
    int newTailpos=length-k;

    //Traversing the list to find the new last node.
    Node* newTail=head;
    for(int i=1; i<newTailpos; i++){
        newTail=newTail->next;
    }

    Node* newHead=newTail->next;
    newTail->next=nullptr;
    
    return newHead;
}

int main(){

    Node* head=nullptr;
  
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);

    cout<<"Orginal List: ";
    printList(head);

    int k;
    cout<<"Enter K: ";
    cin>>k;

    Node* newHead=rotateList(head, k);

    cout<<"List After Rotating K Places: ";
    printList(newHead);

    return 0;
}