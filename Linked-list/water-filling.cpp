#include<bits/stdc++.h>
using namespace std;

/*Approach 
    The water stored depends on the min(leftmax,rightmax)- height[i]
        where leftmax and rightmax is greater than heigh[i]
    To store the leftmax for each height[i]
        we could use and prefix array , performing max(prefix[i-1],prefix[i]) for each i in height
        do similarly for suffix array , starting from the end
    Limitations
        Extra space being used by the Prefix and suffix array*/

/*Better approach 
    Use two pointer left and right 
    intialize left = 0 , right = n-1
    leftmax = 0,rightmax=0
    min(left,right) is the limiting side
    if min is left
        check if left>leftmax
            update leftmax
        else
            water += leftmax - height[left] 
        left++
    if min is right
        if right > rightmax
            update rightmax
        else
            water += righmax -height[right]
        right--*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int water =0;

        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>leftmax){
                    leftmax=height[left];
                }
                else{
                    water+=leftmax-height[left];
                }
                left++;
                
            }
            else{
                if(height[right]>rightmax){
                    rightmax=height[right];
                }
                else{
                    water+=rightmax-height[right];
                }
                
                right--;
            }
            
        }
        return water;
        
    }
};