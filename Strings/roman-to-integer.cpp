#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        char roman;
        int ans;
         
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for(int i = 0 ; i < s.size() ; i++){
            roman = s[i];

            if(mp.find(roman) != mp.end()){
                return -1;
            }

            if(i != s.size() -1 ){
                if(mp[s[i]] < mp[s[i+1]]){
                ans = mp[s[i+1]] - mp[s[i]];
                }
            }


            else{
                ans += mp[s[i]];
            }
        }

        return ans;
        
    }
};