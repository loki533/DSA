#include<bits/stdc++.h>
using namespace std;

/*Same as in the chess problem
    try to place (0-9) by checking if its safe using the 3 condition*/

class Solution {
public:
    bool isSafe(int row , int col,vector<vector<char>>& board,char c){

        for(int i=0;i<9;i++){
            if(board[i][col] == c){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if(board[row][i] == c){
                return false;
            }
        }

        int boxrowstart = 3*(row/3);
        int boxcolstart = 3*(col/3);
        for(int i = 0;i<3;i++){
            for(int j=0; j<3 ;j++){
                if(board[boxrowstart+i][boxcolstart+j] == c){
                    return false;
                }
            }
        }

        return true;

    }

    bool solveSudoku1(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j =0 ;j<9 ;j++){
                if(board[i][j] == '.'){
                    for(char c ='1';c<='9' ;c++){

                        if (isSafe(i,j,board,c)){
                            board[i][j] = c;
                        

                            if(solveSudoku1(board)){
                                return true;
                            }

                            board[i][j]='.';
                        }
                    }
                    return false;//if none of them were safe
                }
            }
        }
        return true; //base case after the entrie puzzle has been completed
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku1(board);
    }
    
};