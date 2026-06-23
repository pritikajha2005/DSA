#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& arr){
    int count=0;
    int maximum=0;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]==1){
            count++;
            maximum=max(maximum,count);
        }else{
            count=0;
        }
    }
    return maximum;
}

int main() {
    vector<int> nums={1,1,0,1,1,1};
    cout<<longestOnes(nums);

    return 0;
}