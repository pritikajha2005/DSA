#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();

    vector<int> ans(n);
    ans[0]=1;
    
    //storing prefix product in ans 
    for(int i=1; i<n; i++) {
        ans[i]=ans[i-1]*nums[i-1];
    }

    //maintaining running suffix product
    int suffix=1;
    for (int i=n-1; i>=0; i--) {
        ans[i]*=suffix;
        suffix*=nums[i];
    }

    return ans;
}

int main() {

    vector<int> nums = {1,2,3,4,5};

    vector<int> ans = productExceptSelf(nums);

    for (int x:ans){
         cout<<x<< " ";
    }
    return 0;     
}