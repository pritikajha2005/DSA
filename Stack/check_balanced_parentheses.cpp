#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string s){

    stack<char> st;
    int n=s.length();

    for(int i=0; i<n; i++){
        //Opening Brackets
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        //Closing Brackets
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){

            if(st.empty()){
                return false;
            }

            if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cout<<"Enter expression: ";
    cin>>s;

    if(isBalanced(s)){
        cout<<"Balanced Parentheses";
    }else{
        cout<<"Not Balanced Parentheses";
    }

    return 0;
}