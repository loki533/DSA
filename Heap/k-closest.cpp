#include<bits/stdc++.h>
using namespace std; 

/*Idea is to store the absolute difference of each element compared to the given number
then use a max-heap (since we are popping the furthest element from the number)
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>> maxheap;
        unordered_map<int,int> map;

        for(int num:arr){
            maxheap.push({abs(x-num),num});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }

        vector<int> ans ;

        while(!maxheap.empty()){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};