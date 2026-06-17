#include<bits/stdc++.h>
using namespace std;

/*Brute force approach 
1.  for each day take the subsequent days as sell days , keep track of the max-profit
2.  Return the max profit*/
class Solution{
    public:
        int stock_buy_sell(vector<int>& nums){
            
            int n = nums.size();
            int max_profit = 0;
            int profit = 0;
            for (int i = 0 ; i<n ;i++){
                for(int j=i+1 ; j<n ; j++){
                    profit = nums[j] - num[i];
                    max_profit = max(max_profit,profit);
                }
            }
            return max_profit;

        }
};

/*Optimal Approach
1.  Find the minimum profit encountered till the present iteration
2.  calculate the profit for that specific minimum iteration*/

class Solution{
    public:
        int stock_buy_sell(vector<int>& nums){
            int n = nums.size();
            int minimum = INT_MAX;
            int max_profit = 0;

            for(int i : nums){
                if (nums[i]<minimum)
                    minimum = nums[i];

                else
                    max_profit= max(max_profit,nums[i] - minimum);
            }

            return max_profit;
        }
    }