#include<bits/stdc++.h>
using namespace std;

/*Key idea
    Idea is to use an unordered_map to store <element,freq>
    now use the freq as a key in a min heap
    now access the first top k after pushin while heap.size() < k*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> hash_map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        for(int i = 0 ; i<nums.size() ; i++){
            hash_map[nums[i]]++;
        }

        for(auto i = hash_map.begin(); i!= hash_map.end();i++){
            minHeap.push({i->second,i->first});
            if (minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> result;
        
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

        
    }
};