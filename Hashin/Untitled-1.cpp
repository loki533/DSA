#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

       int maximum_1s(int arr[],int n)
       {
        int count = 0;
        int max_streak = 0;

        for (int i = 0 ; i<n ;i++)
        {
            if (arr[i]==1)
            {
                count++;
                if(max_streak < count)
                    max_streak = count;
            }

            if (arr[i]==0)
            {
                count=0;
            }
        }

        return max_streak;
       }
}