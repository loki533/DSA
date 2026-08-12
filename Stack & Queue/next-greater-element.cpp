#include<bits/stdc++.h>
using namespace std;

/*key idea is to 
    traverse from right to left and push the elements onto the stack
    make a result array which stores the nge for a given index,
    nge can be found by 
    if st.top()<element
        pop
    else
        res[i] = st.top
    later push the elment onto the stack
    if stack empty the nge becomes -1
    
    since nums1 is a subset of nums2 the nge of each element in nums2 is the same for the nums1*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        int n = nums1.size();
        vector<int> result(n);
        unordered_map<int,int> mp;

        for(auto num : nums2){//if lesser element on top
            while(!st.empty() &&  num>st.top()){
                mp[st.top()] = num;
                st.pop();
            }
                
            st.push(num);
        }

        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }

        for(int i =0;i<n;i++){
            result[i] = mp[nums1[i]];
        }

        return result;
    }
};