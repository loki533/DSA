#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size()<=1){
            return s;
        }

        int start = 0;
        int end = 0;
        string longest_palindrome = "";

        for(int i =0 ; i<s.size() ;i++){
            //check for odd palindromes
            start = i;
            end = i;
            while( (start>=0 && end < s.size() ) && s[start] == s[end]){
                start--;
                end++;
            }

            string palindrome = s.substr(start+1,end-start-1);

            if(palindrome.size() > longest_palindrome.size()){
                longest_palindrome = palindrome;
            }

            //check for even palindromes
            start = i-1;
            end = i;

            while( (start>=0 && end < s.size() ) && s[start] == s[end]){
                start--;
                end++;
            }

            palindrome = s.substr(start+1,end-start-1);

            if(palindrome.size() > longest_palindrome.size()){
                longest_palindrome = palindrome;
            }
        }

        return longest_palindrome;
    }
};