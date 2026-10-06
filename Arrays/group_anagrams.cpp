#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (string s:strs){
            char freq[26]={0};

            for(char c : s){
                freq[c-'a']++;
            }

            string key ;
            for ( int i = 0 ; i<26 ; i++){
                key += to_string(freq[i]);
                key += "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result ;
        
        for(auto &s:mp){
            result.push_back(s.second);
        }

        return result;
    }
};