#include <iostream>
#include <vector>
using namespace std;

int maximum_area(vector<int>& height){
    int maxwater=0;
    int left=0;
    int right=height.size()-1;
    
    while(left<right){
        int width=right-left;
        int h=min(height[left], height[right]);
        int area=h*width;

        maxwater=max(maxwater,area);

        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
     return maxwater; 
}

int main() {
    vector<int> height={2,8,6,5,4,3,7};

    cout<<maximum_area(height)<<endl;
    return 0;
}