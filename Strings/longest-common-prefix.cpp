#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int size = strs.size();

        if (size == 0){
            return "";
        }
        
        sort(strs.begin(),strs.end());

        int shorter= 0;

        string first_string = strs[0];
        string last_string = strs[size-1];

        first_string.size()<last_string.size() ? shorter = first_string.size() : shorter = last_string.size();
        string prefix = "";

        for (int i = 0 ; i < shorter ; i++){
            if ( first_string[i] == last_string[i]){
                prefix += first_string[i];
            }
            else{
                break;
            }
        }

        return prefix;
    }
};