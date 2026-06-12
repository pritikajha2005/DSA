#include <iostream>
#include <vector>
using namespace std;
 
void move_zeros(vector<int>& arr){
    int i=0;
    for(int j=0; j<arr.size(); j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}

int main(){
    vector<int> arr={0,1,0,2,0,3};
    
    move_zeros(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
