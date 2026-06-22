#include<bits/stdc++.h>
using namespace std;

/*Brute Force approach
1.  Sort the array based on the starting range , so that overlappin problems lie nxt to each other
2.  Now use 2 variables start nd end , if end of ith element is greater than start of (i+1)th element 
        merge the problem
3.  Repeat until end of array */


/*Optimal Approach
1.  Again sort the given array such that overlappin intervals lie next to each other
2.  Now use another array , push elements if the array is empty || if array.end()[] < interval[0]
3.  otherwise push the greater end*/

class Solution{
    public:
         vector<vector<int>> merge(vector<vector<int>>& intervals){
           
            sort(intervals.begin(),intervals.end());
            vector<vector<int>> merged; //array to store the result

            for(auto interval:intervals){
                if(merged.empty() || merged.back()[1] < interval[0]){
                    merged.push_back(interval); //no overlapping
                }
                else{
                    merged.back()[1] = max(merged.back()[1],interval[1]);
                }
            }

            return merged;

         }

};