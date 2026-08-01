#include<bits/stdc++.h>
using namespace std;

/*Idea that should first come onto mind when combination is pick/non-pick
    Recursively pick and non pick until all the elements are considered*/


class Solution {
public:
    void findcombination(int index,vector<int>& candidates,int target,vector<int>& ds,vector<vector<int>>& ans){
        if(index==candidates.size()){ //checks if every index has been passed
            if (target == 0){
                ans.push_back(ds);
            }
            return; //prune the branch
        }

        if(candidates[index] <= target){ 
            ds.push_back(candidates[index]);
            findcombination(index,candidates,target-candidates[index],ds,ans);
            ds.pop_back();//backtracking , eliminate to explore new branches
        }
        //not pick
        findcombination(index+1,candidates,target,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds; 

        findcombination(0,candidates,target,ds,ans);
        return ans;
    }
};