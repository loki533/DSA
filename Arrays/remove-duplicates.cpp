#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    to use a set data structure to ensure only unique elements are placed onto it
    return size of the set
    limitation : usage of extra space
*/

/*Optimal Approach
    Use a 2 pointer technique
    where i holds the position of the last unique element
    and j hold as the iterative
    
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; //position of last unique
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return (i+1);
        
    }
};