#include<bits/stdc++.h>
using namespace std;

/*Approach 1
    Check if the given target falls under the specific row
    Condition to check 
        if (nums[row][0] < target && nums[row][no_of_columns])
            -> then apply binary search there*/
class Solution{
    public:
        bool BinarySearch(vector<int>& nums ,int target){

            int low = 0;
            int high = nums.size()-1;
            int mid =0;

            while (low<=high){
                mid = (low+high)/2;

                if(nums[mid] > target){
                    high = mid-1;
                }
                else if (nums[mid] < target){
                    low = mid+1;
                }

                else
                    return true;
                
            }

            return false;
        }

        bool SearchMatrix(vector<vector<int>>& matrix, int target){
            int row = matrix.size();
            int columns = matrix[0].size();

            for (int i =0 ; i<row ; i++){
                if (matrix[i][0] <= target && matrix[i][columns-1] >= target){
                    return BinarySearch(matrix[i],target);
                }
            }

            return false;

        }



};

int main() {
    Solution s;

    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    cout << s.SearchMatrix(matrix, 16);

    return 0;
}