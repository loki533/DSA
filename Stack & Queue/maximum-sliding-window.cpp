#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i< n ;i++){

            if(!dq.empty() && dq.front() <= i-k){//check if out of bound
                dq.pop_front();
            }

            //remove elements which are lesser than the current
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){ // if first window is passed
                result.push_back(nums[dq.front()]);
            }

        }

        return result;
        
    }
};