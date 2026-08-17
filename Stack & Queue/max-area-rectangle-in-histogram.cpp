#include<bits/stdc++.h>
using namespace std;

/*find the nse and pse to calculate width = (nse - pse -1)
now return the max(area)*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;//stores the index
        int leftsmaller[n] ;
        int rightsmaller[n];

        //to calculate left smaller
        for(int i = 0; i<n-1 ; i++){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop(); //pop till smaller element reached
            }

            leftsmaller[i] = st.empty()? 0 : heights[st.top()+1] ; //if stack is empty the lse can be from the first column itself

            st.push(i);
        }

        //clear stack for nse
        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i>=0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            rightsmaller[i] = st.empty()? n-1: heights[st.top()-1];

            st.push(i);
        }

        int max_area=INT_MIN;
        int area ;

        for(int i =0; i<n ;i++){
            area = heights[i] * (rightsmaller[i] - leftsmaller[i] - 1 );
            max_area = max(max_area , area);
        }

        return max_area;
    }
};