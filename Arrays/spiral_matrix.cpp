#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix){

    cout << "Entered function\n";

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "n = " << n << " m = " << m << endl;

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    vector<int> ans;

    while(top <= bottom && left <= right){

        cout << "Loop started\n";

        for(int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        cout << "After top row\n";

        for(int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        cout << "After right column\n";

        if(top <= bottom){
            for(int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        cout << "After bottom row\n";

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }

        cout << "After left column\n";
    }

    cout << "Returning\n";
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral print: "<<endl;

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}