#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum(vector<int>& arr, int target){
    int n=arr.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
    return {};
}

int main(){
    vector<int> arr={2,3,7,4};
    int target=10;

    vector<int> ans=two_sum(arr, target);

    if(ans.empty()){
        cout<<"No pair exists";
    }
    else{
        for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
        }
    }
}