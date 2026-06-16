#include<bits/stdc++.h>
using namespace std;


/*Brute force approach is to 
1. Generate all permuations of the given array
2. Find the asked array nd return the next array in the permuation
3. Problem lies as it uses recrusion for each Permuation O(N!*N) */

/* Better approach would be to use STL library next_permutation in cpp*/

/*Optimal approach
1.  Find breakpoint i.e where the arr[i] < arr[i+1] , since this is the point where the rearrgment of 
    the remaining part can give the nxt permutation
2.  Now the swap the arr[i] with the element i.e just greater than arr[i]
3.  Sort the remaining part of the array

*/

class Solution{
    public:
        void next_permutation(vector<int>& nums){
            int n = nums.size();
            int breakpoint = -1;

            for(int i =0; i<n ; i++){
                if (nums[i] < nums[i+1])
                    breakpoint = i;
            }

            if (breakpoint == -1){
                reverse(nums.begin(),nums.end());
                return;
            }

            for(int i =n; i>=0 ; i--){                              /*2.  Now the swap the arr[i] with the element i.e just greater than arr[i]*/
                if (nums[i] > nums[breakpoint]){
                    swap(nums[i],nums[breakpoint]);
                    break;
                }    
            }

            reverse(nums.begin()+breakpoint+1,nums.end());  /*3rd step*/
        }
};