#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int second_largest_element(vector<int>& arr){
    int largest=INT_MIN;
    int second_largest=INT_MIN;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else{
            if(arr[i]>second_largest && arr[i]!=largest){
                second_largest=arr[i];
            }
        }
    }
    if(second_largest==INT_MIN)
        return -1;
    

    return second_largest;
}

int main(){
    vector<int> arr={2,3,5,7,8,4,3,1};
    cout<<"Second largest element is:"<<second_largest_element(arr);

    return 0;
}