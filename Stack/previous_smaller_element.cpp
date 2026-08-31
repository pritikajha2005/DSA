#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> previousSmallerElement(vector<int>& arr){

    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=0; i<arr.size(); i++){

        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i]=st.top();
        }else{
            ans[i]=-1;
        }

        st.push(arr[i]);
    }
    
    return ans;
}

int main(){

    vector<int> arr={4,5,2,10,8};
    vector<int> ans=previousSmallerElement(arr);

    for(int x : ans) {
        cout<<x<<" ";
    }

    return 0;
}
