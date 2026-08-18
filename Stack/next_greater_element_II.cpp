#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums){
    int n=nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=2*n-1; i>=0; i--){
        int curr=nums[i%n];

        while(!st.empty() && st.top()<=curr){
            st.pop();
        }

        if(i<n){
            if(!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i]=-1;
            }
        }
        
        st.push(curr);
    }

    return ans;
}

int main(){
    vector<int> nums={1,2,3,4,3};
    vector<int> ans=nextGreaterElement(nums);

    for(int x: ans){
        cout<<x<<" ";
    }
    
    return 0;
}