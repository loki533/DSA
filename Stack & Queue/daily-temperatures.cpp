#include<bits/stdc++.h>
using namespace std;

/*
Idea is to store the unresolved index 
keep pushing till the warmer temperature arrives (compare the new temp with the top)
Stack , perfect since we need the most recent day to be checked with 
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> st;
        for(int i = 0; i<n ; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int prev = st.top();
                st.pop();
                result[prev] = i - prev;
            }
            st.push(i);
        }
        return result;
    }
};