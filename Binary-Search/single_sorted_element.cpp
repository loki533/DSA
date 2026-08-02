#include<bits/stdc++.h>
using namespace std;

/*Approach is 
    [1,1,2,2,3,4,4,5,5]
    pairs are (0,1),(2,3),(4),(5,6),(6,7)
    so before the unique elements the pairs are (even,odd)& later it becomes (odd,even)*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1){
            return nums[0];//only 1 element
        }

        if(nums[0] != nums[1]){ //unique elemnet is first element , handling edge case so that it doesnt go out of bounds
            return nums[0];
        }

        if(nums[n-1]!= nums[n-2]){
            return nums[n-1];
        }

        int low =1 ;
        int high = n-2;//edge case already handled
        

        while(low<=high){

            int mid = (low+high)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid]!= nums[mid+1]){
                return nums[mid];
            }

            if (mid%2 == 1 && nums[mid] == nums[mid-1] || mid%2 == 0 && nums[mid+1]==nums[mid]){
                low = mid+1; //move to right half
            }
            else{
                high = mid-1;
            }
        }
        
    }
};