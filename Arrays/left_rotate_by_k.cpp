#include <iostream>
#include <vector>
using namespace std;

void leftRotateByK(vector<int>& arr, int k){
    int n=arr.size();
    k=k%n;

    vector<int> temp;
    for(int i=0; i<k; i++){
        temp.push_back(arr[i]);
    }

    for(int i=k; i<n; i++){
        arr[i-k]=arr[i];
    }

    for(int i=0; i<k; i++){
        arr[n-k+i]=temp[i];
    }
}

int main(){
    vector<int> arr={1,2,3,4,5,6};
    int k=3;
    leftRotateByK(arr, k);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    } 

    return 0;
}