#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& arr){
    int n=arr.size();
    int count=0;

    for(int i=0; i<n; i++){
        if(arr[i]>arr[(i+1)%n]){
            count+=1;
        }
    }

    return count<=1;
}

int main(){
    vector<int> arr={3,4,5,1,2};
    if(check(arr)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}