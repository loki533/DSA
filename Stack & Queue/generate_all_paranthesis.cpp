#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<string> result;
    public:
        void Backtrack(int n , int open , int close , string current){
            if(current.size() == 2*n){
                result.push_back(current);
                return;
            }
            if(open < n){
                //dont modify as current += "("
                //this would result in permanently modifying the current value 
                //by which after the backtracking , it reaches the intial call ... the current would 
                //have changed by then 
                // better use this so that each call stores its own copy.
                Backtrack(n,open+1,close,current+"(");
            }
            if(close<open){
                Backtrack(n,open,close+1,current+")");
            }
        }
        vector<string> generateParenthesis(int n) {
            Backtrack(n , 0 , 0 ,"");
            return result;
        }
    };