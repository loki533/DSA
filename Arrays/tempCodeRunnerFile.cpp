#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        for (int i=0 ; i< rows ; i++){
            for (int j=0; j<columns ;j++){

                if (matrix[i][j]==0){ /*if the present element is 0*/

                    for (int k = 0 ; k < columns ; k++){ /*marks every element in the specific column 0 as -1 except the pre-exisiting 0*/
                        if (matrix[i][k] != 0)
                            matrix[i][k] = -1;
                    }

                    for (int l=0; l < rows ; l++){   /*marks every element in the specific row 0 as -1 except the pre-exisiting 0*/
                        if (matrix[l][j] != 0){
                            matrix[l][j] = -1;
                        }
                    }
                    
                }

            }
        }

        /* replace all the -1s with 0s*/
        for (int i=0 ; i< rows ; i++){
            for (int j=0; j<columns ;j++){
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;

            }
        }    
}
};