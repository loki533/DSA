#include<string>
using namespace std;

class  Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    int check[26] = {0};

    for (char c : magazine)
    {
        check[c - 'a']++;
    }

    for (char c : ransomNote)
    {
        check[c - 'a']--;
        if (check[c-'a'] < 0)
        return false;
    }
    return true;
    
    }
};