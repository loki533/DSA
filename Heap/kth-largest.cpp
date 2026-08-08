#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = nums.size();
        if(n<k){
            return -1;
        }

        for(int x:nums){
            minHeap.push(x);
        }

        while(minHeap.size()>k){
            minHeap.pop();
        }

        return minHeap.top();

    }
};