#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        long long  number = 0;
        int i = 0;
        
        while(i < size && s[i] == ' '){//skip whitespaces
            i++;
        }

        if (i == size){ //'          '
            return 0;
        }

        bool negative = false;

        if (s[i] == '-'){
            i++;
            negative = true;
        }

        else if (s[i] == '+'){
            i++;
        }

        else if (!isdigit(s[i])){
            return 0;
        }

        if(i == size){
            return 0;
        }

        //skip leading zeroes
        while (i < size && s[i] == '0'){
            i++;
        }

        if ( i == size){//no more characters
            return 0;
        }

        int digit = 0;
        int max = INT_MAX /10;
        int min = INT_MIN / 10;


        while( i < size && isdigit(s[i])){

            digit = s[i] - '0' ;
            i++;

            if (number > max ){
                return INT_MAX;
            }

            else if (number == max && digit >7){
                return INT_MAX;
            }

            if (number < min){
                return INT_MIN;
            }

            else if (number == min && digit >8){
                return INT_MIN;
            }

            if (negative){
                number = number * 10 + (-digit);
            }
            else{
                number = number * 10 + (digit);
            }
        }

        return number;

    }
};