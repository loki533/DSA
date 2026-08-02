#include<bits/stdc++.h>
using namespace std;

/*Recursive approach is to
    1.For each row of each column check if it safe to place
    2.Safe function if there is an existing queen in the left of the row/lower left diagnal / upper left diaognal
    3.If safe , place the queen
    4. add backtracking to remove the queen if it doesnt meet the req
    5.Base case , all rows have been passed*/

/*Optimal approach
    Use hashing 
    Use 3 arrays -> row , upper diagonal,lower diagonal
    such that before placing a queen check if a queen is placed in a vuln position
    lower diagonal = row+col
    upper diagonal =(n-1)+(col-row)*/


class Solution {
public:
    void solve(int col,int n,vector<string>& board,vector<vector<string>>& ans,vector<int>& leftrow,vector<int>& lower_d,vector<int>& upper_d){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upper_d[n-1+(col-row)]==0 && lower_d[row+col] ==0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upper_d[n-1+(col-row)] = 1;
                lower_d[row+col] = 1;
                solve(col+1,n,board,ans,leftrow,lower_d,upper_d);
                //Bactrack
                board[row][col] = '.';
                leftrow[row] = 0;
                upper_d[n-1+(col-row)] = 0;
                lower_d[row+col] = 0;


            }

        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));/*[. . . .]
                                                [. . . .]*/
        vector<int> leftrow(n,0);
        vector<int> lower_d (2*n-1,0);
        vector<int> upper_d (2*n-1,0);
        solve(0,n,board,ans,leftrow,lower_d,upper_d);
        return ans;
    }
};