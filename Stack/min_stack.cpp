#include <iostream>
#include <stack>
using namespace std;

class MinStack{
    stack<int> st;
    stack<int> minSt; 

public:

    void push(int val){
        st.push(val);

        if(minSt.empty() || val<=minSt.top()){
            minSt.push(val);
        }
    } 
    
    void pop(){
        if(st.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }

        if(st.top()==minSt.top()){
            minSt.pop();
        }
        st.pop();
    }

    int top(){
        if(st.empty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

        return st.top();
    }

    int getMin(){
        if(minSt.empty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

        return minSt.top();
    }   
};

int main(){
    MinStack s;

    s.push(5);
    s.push(7);
    s.push(4);
    s.push(2);

    cout<<"Top: "<<s.top()<<endl;
    cout<<"Minimum: "<<s.getMin()<< endl;

    s.pop();

    cout<<"After pop:"<<endl;
    cout<<"Top: "<<s.top()<<endl;
    cout<<"Minimum: "<<s.getMin()<< endl;

    s.pop();

    cout<<"After another pop:"<<endl;
    cout<<"Top: "<<s.top()<<endl;
    cout<<"Minimum: "<<s.getMin()<< endl;
    
    return 0;
}
