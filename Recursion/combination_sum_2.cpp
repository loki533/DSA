#include<bits/stdc++.h>
using namespace std;

/*In combination-sum 2
    the major difference is unlike the combination-sum1 , there can be duplicate elements in the array 
    and u cannot chose an element infinite number of times*/

/*Approach 1 
    follow the same approach as Combination-sum1 , by moving index to next in picking
    and returning the ans list as a hash set*/

/*draw recursion tree first to get better idea*/

class Solution {
public:
    void findcombination2(int index,vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<candidates.size() ; i++){
            if(i!=index && candidates[i]==candidates[i-1]) //to avoid duplicate combination , this line avoids same element being starting
                continue;
            if(candidates[i]>target)
                break;
            
            ds.push_back(candidates[i]);
            findcombination2(i+1,candidates,target-candidates[i],ans,ds);
            ds.pop_back(); //backtracking with removin the element
        }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findcombination2(0,candidates,target,ans,ds);
        return ans;
    }
};