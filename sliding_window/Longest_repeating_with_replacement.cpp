#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);

        int left = 0;
        int Max_freq = 0;
        int ans = 0;

        for (int right= 0 ; right<s.size() ; right++){
            freq[s[right]-'A']++;
            Max_freq = max(Max_freq , freq[s[right] - 'A']);

            int changes = (right-left+1) - Max_freq;
            if(changes>k){
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(right-left+1,ans);
        }
        return ans;
    }
};