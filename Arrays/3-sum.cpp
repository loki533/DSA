#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        int size = nums.size();

        sort(nums.begin(),nums.end());

        for(int i = 0;i<size ; i++){
            //skip duplicate
            if (i>0 && nums[i] == nums[i+1]){
                continue;
            }

            int left = i+1;
            int right = size-1;

            while(left<right){
                if (nums[i] + nums[left] +nums[right] == 0){
                    result.push_back({nums[i],nums[left],nums[right]});

                    left++;
                    right--;

                    //skip duplicate left
                    while (left<right && nums[left] == nums[left-1]){
                        left++;
                    }

                    while  (left<right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                
                else if (nums[i] + nums[left] +nums[right] < 0){
                    left++;
                }

                else{
                    right --;
                }
                
            }
        }

        return result;
    
    }
};