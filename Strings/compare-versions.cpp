#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> tokenize(string version){
        stringstream ss (version);
        string token = "";
        vector<string> tokens ;

        while(getline(ss,token,'.')){
            tokens.push_back(token);
        }

        return tokens;
    }

    int compareVersion(string version1, string version2) {
        vector<string> tokens1;
        vector<string> tokens2;

        tokens1=tokenize(version1);
        tokens2 = tokenize(version2);

        int size1 = tokens1.size();
        int size2 = tokens2.size();
        int cmp_size = 0;

        size1>size2?cmp_size=size1:cmp_size = size2;
        int cmp = 0;
        int i =0;
        int a = 0;
        int b =0;

        for (int i = 0 ;i < cmp_size ; i++){
            int a = (i < size1) ? stoi(tokens1[i]) : 0;
            int b = (i < size2) ? stoi(tokens2[i]) : 0;

            if (a > b) return 1;
            if (a < b) return -1;
       }

       return 0;
        
    }
};