#include<bits/stdc++.h>
using namespace std;

/*Brute force 
    use 2 loops 
    for each element iterate the next set for target*/

/*Better approach
    use Hashmap
        for each element check if complement(target - element) exits in the hashmap*/

/*Optimal approach
    Sort array first in ascending
        use 2 pointers ( start nd end)
        if (arr[start] + arr[end] > target) -> end--
        else if (arr[start] + arr[end ] < target )-> start ++*/
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){


        vector<pair<int,int>> nums_original_indices;
        int n = nums.size();

        

        for(int i = 0 ; i< n;i++){
            nums_original_indices.push_back({nums[i],i});

        }
        sort(nums_original_indices.begin(), nums_original_indices.end());
        
        int start = 0;
        int end = n-1;
        
        while(start<end){
            int sum = (nums_original_indices[start].first + nums_original_indices[end].first);
            if (sum == target){
                return {nums_original_indices[start].second,nums_original_indices[end].second};
            }

            else if (sum < target){
                start++;
            }
            else{
                end--;
            }
        }

        return {-1,-1};

    }
};