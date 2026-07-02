#include<bits/stdc++.h>
using namespace std

/*Brute force approach
    use a set to store unique vectors
    use 3 loops
    if their sum meets the req. sort nd add em to the set
*/

/*Better approach
    Use a set to store the unique vectors
        Now instead of 3 loops use 2 loops
            after findin the first 2 elements ,check if  - (sum- 1st + 2nd) exists,if not add it to the hashset 
                if exists store into the set result
*/

/*Optimal approach
    Sort the array , skip duplicates
    Use 2 pointers ,  left nd right
    if the sum is greater than target
        move the right pointer to the left
    if less 
        move left pointer to right
    if equal
        store onto the result vector
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
    }
};