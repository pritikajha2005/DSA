#include <iostream>
#include <vector>
using namespace std;

int largest_element(vector<int>& arr){
    int largest=arr[0];

    for(int i=1; i<arr.size(); i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int main(){
    vector<int> arr={2,3,6,4,7};
    cout<<"Largest element is: "<<largest_element(arr);

    return 0;
}