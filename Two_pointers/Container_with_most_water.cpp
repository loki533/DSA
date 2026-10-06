#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maximum_water = INT_MIN;
        long long area = 0;
        long long h = 0;
        long long width = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right){
            width = right - left;
            h = min(height[left],height[right]);
            area = width * h ;
            maximum_water = max(maximum_water , area);


            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }

        }

        return maximum_water;
    }

};