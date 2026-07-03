#include<bits/stdc++.h>
using namespace std;

/*Greedy Approach
    sort the greed nd size array
    Now use 2 pointers L and R (L -> greed ) nd vice versa
    If greed[L]<=size[R] 
        number++ nd L++,R++*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int number =0;
        int n= g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int greed_id =0;
        int size_id=0;

        while(greed_id<n && size_id<m){
            if(g[greed_id]<=s[size_id]){
                number++;
                greed_id++;
            }
            size_id++;
        }
        return number;

    }
};