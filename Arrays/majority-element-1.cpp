#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    count occurence of each element 
        if greater than n/2 then return it*/

/*Better approach
    Use hashmap to store element,occurence pair
        unordered_map<int,int> mp
            mp[element]++
        After that check if mp[element] > n/2 , return element*/

/*Optimal Approach
    MOORE's ALGORITHM
        working 
            by cancelling the number of odd pairs , the final remaining element is the majority
            think of as if counting votes , initially there is no favourites
                as the no of supporters increase ,increase the count .


    use two variables 
        count->to store the occurnce (initialized to 0)
        element -> stores the current element
    Logic
        if count = 0, the present element becomes the element
        if current element is same as element , increment count
        if diff , decrement count 
        
        At the end , the element is supposed to be majority element , Verify it !!*/

class Solution {
public:
    int majorityElement(vector<int>& nums){

        int count = 0;
        int element = 0;

        for (int i = 0 ; i< nums.size() ; i++){
            if (count == 0){
                element = nums[i];
                count++;
            }

            else if (nums[i] == element){
                count++;
            }

            else{
                count--;
            }
        }

        //verifyin
        int count_verify = 0;
        for (int i =0;i<nums.size() ; i++){
            if (nums[i]==element){
                count_verify++;
            }
        }
        int n = nums.size();
        if (count_verify> n/2){
            return element;
        }

    }
};