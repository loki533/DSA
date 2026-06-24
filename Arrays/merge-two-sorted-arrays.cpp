#include<bits/stdc++.h>
using namespace std;

//have 3 pointers 
            /*1. i, which tracks the last valid index before Zeros
              2. j, which tracks the last valid index including zeros
              3. k, last index of the 2nd array*/  
            // m-> size of nums1 , n-> size of nums2

class Solution{
    public:
        void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // i points to the last valid element in nums1
    int i = m - 1;

    // j points to the last element in nums2
    int j = n - 1;

    // k points to the last position in nums1
    int k = m + n - 1;

    // Fill nums1 from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from nums2
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
        }
};
