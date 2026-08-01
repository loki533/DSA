#include<bits/stdc++.h>
using namespace std;

/*Apporoach is to swap the index value with every element from index to end*/

class Solution {
public:
    void generate_permute(int index,vector<int>& nums,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            generate_permute(index+1,nums,ans);
            swap(nums[i],nums[index]);//backtracking
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate_permute(0,nums,ans);
        return ans;
    }


};