#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n=matrix.size();
    
    //Transpose 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reverse each row
    for(int i=0; i<n; i++){
        int left=0;
        int right=matrix[i].size()-1;
        
        while(left<right){
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }

}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    rotate(matrix);

    cout<<"Rotated Matrix :"<<endl;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}