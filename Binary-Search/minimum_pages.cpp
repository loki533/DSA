#include<bits/stdc++.h>
using namespace std;

/*Idea 
    initialize low with max/min of the array since anyways a student has to take 1 book
    high would be the sum of the array
    now mid would act as a boundary on how much pages it can be assigned
    go on with classic binary search , by checkin if those many students can be assignmed with mid no of pages
    if yes , go to the right half
    if no , go to left half*/

class Solution {
  public:
    bool Allocation_poss(long long mid,vector<int>& arr,int k){

        int students =1;
        long long pages =0;
        int n= arr.size();
        for (int i =0;i<n;i++){

            if(arr[i]>mid){
                return false;
            }

            if(pages+arr[i]>mid){
                students++;
                pages=arr[i];
            }

            else{
                pages+=arr[i];
            }

        }

        if(students >k ){
            return false;
        }

        else{
            return true;
        }
    }


    long long findPages(vector<int> &arr, int k) {

        long long low =INT_MIN;
        long long high=0;
        long long n = arr.size();

        if(n<k){
            return -1;
        }

        for(int i=0;i<n ;i++){

            low=max(low,(long long) arr[i]);
            high += arr[i];
        }

        while(low<=high){

            long long mid = (low+high)/2;

            if (Allocation_poss(mid,arr,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }

        return low;
        
    }
};