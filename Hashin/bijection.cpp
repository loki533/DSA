#include<string>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while(ss >> word)
        {
            words.push_back(word);
        }

        if (words.size() != pattern.size())
            return false;
        
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;

        for (int i = 0 ; i < words.size() ; i++)
        {
            char ch = pattern[i];
            string s = words[i];

            if(mp1.count(ch)  && mp1[ch]!=s)
                return false;

            if(mp2.count(s) && mp2[s]!= ch)
                return false;
            
            mp1[ch] = s;
            mp2[s] = ch;
        }

        return true;

    }