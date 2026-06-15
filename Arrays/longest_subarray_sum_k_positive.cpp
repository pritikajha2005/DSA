#include <iostream>
#include <vector>
using namespace std;

int longest_subarray(vector<int>& arr, int k){
    int left=0;
    int sum=0;
    int maxlen=0;

    for(int right=0; right<arr.size(); right++){
        sum+=arr[right];

        while(sum > k){
            sum-=arr[left];
            left++;
        }
    
       if(sum==k){
         maxlen=max(maxlen, right-left+1);
       }
    }
    return maxlen;
}
int main(){
    vector<int> arr={1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k=3;

    cout<<longest_subarray(arr,k);
    return 0;
}