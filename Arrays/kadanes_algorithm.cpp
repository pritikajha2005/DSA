#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximum_subarraySum(vector<int>& arr){
    int current_sum=0;
    int maximum_sum=INT_MIN;

    for(int i=0; i<arr.size(); i++){
        current_sum+=arr[i];

        maximum_sum=max(maximum_sum, current_sum);
        
        if(current_sum<0){
            current_sum=0;
        }
    }
    return maximum_sum;
}

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum subarray sum is "<<maximum_subarraySum(arr);
    
    return 0;
}