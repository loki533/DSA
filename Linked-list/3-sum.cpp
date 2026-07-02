#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    use a set to store unique vectors
    use 3 loops
    if their sum meets the req. sort nd add em to the set
*/

/*Better approach
    Use a set to store the unique vectors
        Now instead of 3 loops use 2 loops
            after findin the first 2 elements ,check if  - (sum- 1st + 2nd) exists,if not add it to the hashset 
                if exists store into the set result
*/

/*Optimal approach
    Sort the array , skip duplicates
    Use 2 pointers ,  left nd right
    if the sum is greater than target
        move the right pointer to the left
    if less 
        move left pointer to right
    if equal
        store onto the result vector
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        int n = nums.size();

        for(int i=0 ;i<n;i++){

            if (i>0 && nums[i] == nums[i+1])
                continue;
            
            int left= i+1;
            int right = n-1;

            while(left<right){

                if(nums[left]+nums[right]+nums[i] <0)
                    left++;

                else if(nums[left]+nums[right]+nums[i]>0)
                    right--;
                
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    //here we are goin to check for every combination for the current ith element
                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1])right--;

                }
                    

            }

            
        }

        return result;
        
    }
};