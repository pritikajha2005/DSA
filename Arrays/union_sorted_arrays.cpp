#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;
    vector<int> result;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(result.size()==0 || result.back()!=a[i]){
                result.push_back(a[i]);
            }
            i++;
        }
        else{
            if(result.size()==0 || result.back()!=b[j]){
                result.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(result.size()==0 || result.back()!=a[i]){
                result.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(result.size()==0 || result.back()!=b[j]){
                result.push_back(b[j]);
        }
        j++;
    }

    return result;
}

int main(){
    vector<int> arr1={1,1,2,3,4,5};
    vector<int> arr2={2,3,4,4,6};

    vector<int> result= findUnion(arr1,arr2);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
}