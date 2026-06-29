#include <iostream>
#include <vector>
using namespace std;

int missing_number(vector<int>& arr){
    int n=arr.size();
    int totalSum=n*(n+1)/2;
    int arraySum=0;

    for(int i=0; i<arr.size(); i++){
        arraySum+=arr[i];
    }

    int missingNumber=totalSum-arraySum;

    return missingNumber;
}

int main(){
    vector<int> arr={1,2,3,4,6};
    
    cout<<missing_number(arr);
    return 0;
}