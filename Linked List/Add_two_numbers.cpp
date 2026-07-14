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

Node* addTwoNumbers(Node* L1, Node* L2){
    
    Node* dummyHead= new Node(-1);
    Node* current=dummyHead;
    Node* temp1=L1;
    Node* temp2=L2;
    int carry=0;

    while(temp1 != NULL || temp2 != NULL || carry!=0){
        int sum=carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;

        Node* newNode=new Node(sum%10);
        carry=sum/10;
        current->next=newNode;
        current=current->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    return dummyHead->next;  
}

int main(){
    Node* L1=nullptr;
    Node* L2=nullptr;
    //Number 456
    insert(L1, 6);
    insert(L1, 5);
    insert(L1, 4);
    //Number 342
    insert(L2, 2);
    insert(L2, 4);
    insert(L2, 3);

    Node* result= addTwoNumbers(L1, L2);

    cout<<"Result: ";
    printList(result);
    
    return 0;
}