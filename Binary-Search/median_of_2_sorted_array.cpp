#include<bits/stdc++.h>
using namespace std;

/*Idea is to determine the cut points
    such that array1 is lesser in size than array2
        condititions to look for are l1(leftmost element selected from array 1) <= r2(rightmost element selected from array2)
                                     l2<=r1
    use binary search to determinte the cut point
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        //go wit the smaller array first , to reduce the search space
        if(n1>n2){
            return (findMedianSortedArrays(nums2,nums1));
        }
    

        int low=0;
        int high=n1;
        
        while(low<=high){
            int cut1 = low+(high-low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;

            int l1=  cut1 == 0?INT_MIN:nums1[cut1-1];
            int l2 = cut2==0?INT_MIN:nums2[cut2-1];
            int r1= cut1 == n1?INT_MAX:nums1[cut1];
            int r2 = cut2==n2?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if( (n1+n2)%2 ==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return (max(l1,l2));
            }

            else if(l1>r2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        
    }
};