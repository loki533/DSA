#include<bits/stdc++.h>
using namespace std;

/*Brute force approach 
    Use 4 loops to iterathe through nd find if it matches the target
    Use a set to only store unique quadrples*/

/*Better approach
    Use 3 loops , later use a hashmap to check if complement exits
    if yes , add nd return the unique quadrples
    if no , add the element to hashmap*/

/*Optimal approach
    sort the array
    Use 2 nested loops
        if current nd previous element are the same skip them to avoid duplicates,in both loops
        Initialize start variable with the element after the 2nd loop variable
        intialize the end variable with the last
            if sum of both is less -> start++
            if greater -> end--*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;

        for(int i =0 ;i<n-1;i++){
            if (i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for (int j = i+1; j<n-1;j++){
                if (j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
            
            int left = j+1; int end = n-1;
            while(left < end){
                long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[end];

                if(sum == target){
                    result.push_back({nums[i],nums[j],nums[left],nums[end]});
                

                // Move left pointer skipping duplicates
                while (left < end && nums[left] == nums[left + 1])
                        left++;
                // Move right pointer skipping duplicates
                while (left < end && nums[end] == nums[end - 1])
                        end--;
                    
                left++;
                end--;
                }
                
                
                else if (sum<target){
                    left++;
                }
                else
                    end--;

                }

            }
        }
    
        
    }
    return result;
};