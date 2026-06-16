#include<bits/stdc++.h>
using namespace std;

/*Brute force Approach 
 however this doesnt work if the marker being used pre-exists in the arrayg*/

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

/* Better approach to mark which rows and columns are supposed to b marked as zero
-> use 2 different arrays row and column which marks the the rows and columns that are to b marked with 0
-> Later check if either the column or row was marked & mark the correspondin element as 0*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n_rows = matrix.size();
        int n_columns = matrix[0].size();

        vector<int> rows(n_rows,0);
        vector<int> columns(n_columns,0);

        for (int i=0;i<n_rows;i++){
            for (int j=0 ; j< n_columns;j++){
                if (matrix[i][j] == 0){
                    rows[i]=1;
                    columns[j]=1;
                }
            }
        }

        for (int i=0;i<n_rows;i++){
            for (int j=0;j< n_columns;j++){
                if (rows[i] == 1 || columns[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*most Optimal approach
-> use the 1st row and 1st column itself to mark if the respective rows nd columns are to b marked 0
-> take 2 flags to track if there is a 0 in the first_row or in the first_column
-> iterate thru rest of the matrix nd mark the row/column in the first 
-> place 0s for the rest of the matrix
-> place 0s for 1st row nd column if flag true*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n_columns = matrix[0].size();
        int n_rows = matrix.size();

        bool rowZero = false ;
        bool columnZero = false ;

        
    }
}

