#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    vector<int> results , can only hv 2 elements whos occurence is greater than n/3
    now for each unique element in nums , if not exisiting in results
    count its occurence , if greater than n/3 -> add it to the result array*/

/*Better approach
    Just like in majority element 1 , use a hashmap unordered_map<int,int> mp
        mp[element]++ , later check for element with occurence > n/3*/

/*Optimal approach
    Do the similar approach used for Majority-element-1
        here use 4 variables
        count1,count2,element1,element2
        if (count1 ==0)
            -> element1 = num[i]
        if (count2 == 0)
            -> element2 = num[i]
        if (elemen1 == num[i])
            -> count1++
        if (element2 == num[i])
            -> count2++
        else
            decrement both
        
    Later check if ans if correct    */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int element1=0;
        int element2= 0;
        int n = nums.size();

        for (int i =0 ; i< n;i++){
            if (nums[i] == element1)
                count1++;
            else if (nums[i] == element2)
                count2++;
            else if (count1 == 0)
            {
                element1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                element2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }

        }

        vector<int> result;

        int count1_check =0;
        int count2_check = 0;

        for (int i = 0 ;i < n;i++){
            if (nums[i] == element1){
                count1_check++;
            }
            else if (nums[i] == element2){
                count2_check++;
            }
        }

        
        if (count1_check > n/3 ){
            result.push_back(element1);

        }

        if(count2_check>n/3){
            result.push_back(element2);
        }

        return result;
        
    }
};