#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>& arr, int k){
    unordered_map<int,int> mp;

    int prefix=0;
    int maxLen=0;

    for(int i=0; i<arr.size(); i++){
        prefix += arr[i];
        // If the prefix sum itself equals k, then the subarray from index 0 to i is a valid answer.
        if(prefix==k){
            maxLen=i+1;
        }
        //Check if there exists a previous prefix sum, such that currentPrefix - previousPrefix = k.
        if(mp.find(prefix-k)!=mp.end()){
            int len=i-mp[prefix-k];
            maxLen=max(maxLen, len);
        }
        
        // Store only the first occurrence of each prefix sum.
        if(mp.find(prefix)==mp.end()){
            mp[prefix]=i;
        }
    }
    return maxLen;
}
int main() {
    vector<int> arr={1,2,2,1,1,1,1,4};
    int k=4;

    cout<<longestSubarray(arr, k);

    return 0;
}