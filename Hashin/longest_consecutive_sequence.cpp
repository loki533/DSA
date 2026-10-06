#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int temp = 0;
        int length = 0 ;
        int longest = INT_MIN;

        if(nums.size() == 0){
            return 0;
        }

        for(int i =0 ; i <nums.size() ;i++){
            st.insert(nums[i]);
        }

        for (auto it : st){
            if(st.find(it-1) == st.end()){
                temp = it;
                length = 1;
            }

            while(st.find(temp+1) != st.end()){
                length++;
                temp++;
            }

            longest = max(length,longest);
        }

        return longest;
        
    }
};