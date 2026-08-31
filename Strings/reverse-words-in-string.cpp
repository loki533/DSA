#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int size = s.size()-1;
        string result = "";
        string word = "";

        int i = size;
        int end = 0;

        while(i>=0){
            //to remove trailing spaces
            while(i>=0 && s[i] ==' '){
                i--;
            }

            if(i<0)
                break;//bound check

            end = i;
            
            //to find the starting of the word
            while(i>=0 && s[i] != ' '){
                i--;
            }

            word = s.substr(i+1,end-i);//substr(position,length)

            if(!result.empty()){
                result += ' ';
            }
            result += word;

        }
        return result;
    }


};