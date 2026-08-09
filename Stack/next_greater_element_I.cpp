#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1; i>=0; i--){

        //Removing elements that are not useful
        while(!st.empty() && st.top()<= arr[i]){
            st.pop();
        }
        
        //If stack is empty, no greater element exists
        if(st.empty()){
            ans[i]=-1;
        }
        //If stack is non empty the top most element is the next greater element
        else{
            ans[i]=st.top();
        }
        //Cuurent element becomes a candidate
        st.push(arr[i]);
    }
    
    return ans;

}

int main(){

    vector<int> arr={4,5,2,10,8};

    vector<int> ans=nextGreaterElement(arr);

    for(int x : ans) {
        cout<<x<<" ";
    }

    return 0;
}