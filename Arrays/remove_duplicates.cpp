#include <iostream>
#include <vector>
using namespace std;

int remove_duplicates(vector<int>& arr){
    int i=0;
    for(int j=1; j<arr.size(); j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}
int main(){
    vector<int> arr={1,1,2,2,3,3,4,4};

    int k=remove_duplicates(arr);
    cout<<"Array after removing duplicates ";
    for(int i=0; i<k; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}