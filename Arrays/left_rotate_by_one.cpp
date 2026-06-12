#include <iostream>
#include <vector>
using namespace std;

void leftRotateByOne(vector<int>& arr){
    int n=arr.size();

    int first=arr[0];

    for(int i=1; i<n; i++){
        arr[i-1]=arr[i];
    }

    arr[n-1]=first;
}

int main(){
    vector<int> arr={1,2,3,4,5};

    leftRotateByOne(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    } 
    return 0;
}