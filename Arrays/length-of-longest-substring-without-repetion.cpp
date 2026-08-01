#include<bits/stdc++.h>
using namespace std;

/*Brute Force approach
    use a vector of 256 character to mark if characters hv been visited or not
        for each element that is not visited
            mark them as visited , nd update the max_length variable*/

/*Optimal approach
    Use a hashmap which tracks if visited or not
    Use 2 variables
    one which tracks the occurence of the nxt unique character
    nd the other one tracks all*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];

        for(int i=0;i<256;i++){
            hash[i]=-1;
        }

        int l=0;
        int r = 0;
        int length =0;
        int max_length = 0;

        while(r < s.size()){
            if(hash[s[r]] !=-1) // visited
            {
                l = max(l,hash[s[r]]+1);
            }

            length = r-l+1;
            max_length=max(max_length,length);

            hash[s[r]] = r;
            r++;
        }

        return max_length;

        
    }
};